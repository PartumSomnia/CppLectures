#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <thread>
/*
 * a method to visually represent the performance of 
 * different parts of the code
 * 
 * The method is based on the class Timer() 
 * (see "Lec74_Benchmark" for the details on that 
 * and the new custom designed class "InstrumentationSession"
 * that allows to print the resulted timestamps into 
 * a .json file in a format readably by 
 * "Google chrome://tracing/" 
 * The approach is based on sessions -- 
 * Once you instanciate a session, all the soped performances
 * are logged into a single .json
 * For a new Seession a new .json will be created.
 * 
 * The application can be hidden by macros -- thus 
 * not affecting the code perforamce 
 * 
 * VERY USEFULL
 * 
 * 
 * USe -pthread for linker options to make pthread working 
 * 
 * 
 * 
 */ 

struct ProfileResult
{
	std::string Name;
	long long Start, End;
	uint32_t threadID; // for multithreaded
};

struct InstrumentationSession
{
	std::string Name;
	InstrumentationSession(const std::string& name) : Name(name) { }
};

class Instrumentor
{
private:
	InstrumentationSession* m_CurrentSession;
	std::ofstream m_OutputStream;
	int m_ProfCount;
public:
	Instrumentor()
		: m_CurrentSession(nullptr), m_ProfCount(0)
	{
	}
	
	// Open the .jsom and write the header and instanciate the Timer Storage
	void BeginSession(const std::string& name, const std::string& filepath = "/home/vsevolod/results.json")
	{
		m_OutputStream.open(filepath);
		WriteHeader();
		m_CurrentSession = new InstrumentationSession( name );
	}
	
	// writes the end of the .json file, closes the file, cleans the memory
	void EndSession()
	{
		WriteFooter();
		m_OutputStream.close();
		delete m_CurrentSession;
		m_CurrentSession = nullptr;
		m_ProfCount = 0;
	}
	
	// write the data in expected format into the file
	void WriteProfile(const ProfileResult& result)
	{
		if (m_ProfCount++ > 0)
			m_OutputStream << ",";
		
		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"',  '\'');
		
		m_OutputStream << "{";
		m_OutputStream << "\"cat\":\"function\",";
		m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
		m_OutputStream << "\"name\":\"" << name << "\",";
		m_OutputStream << "\"ph\":\"X\",";
		m_OutputStream << "\"pid\":\"0\",";
		m_OutputStream << "\"tid\":" << result.threadID << ',';   //  "\"tid\":\"0\",";
		m_OutputStream << "\"ts\":" << result.Start;
		m_OutputStream << "}";
		
		m_OutputStream.flush(); // in case of crash -- the data is written 
	}
	
	// write beginning of the .json file for the Chrome Tracing
	void WriteHeader()
	{
		m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
		m_OutputStream.flush();
	}
	
	void WriteFooter()
	{
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}
	
	// used to create a new instance of the class allocated on HEEP!
	static Instrumentor& Get()
	{
		static Instrumentor* instance = new Instrumentor();
		return *instance; // return de-referenced object
	}
	
};

class InstrumentationTimer
{
public:
	InstrumentationTimer(const char* name)
		: m_Name(name), m_stop(false)
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}
	
	~InstrumentationTimer()
	{
		if (!m_stop)
		{
			Stop();
		}
	}
	
	void Stop()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		
		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
		
		// output the result into the consol
		//std::cout << m_Name << ": " << (end - start) << "ms" << std::endl;
		// save the result into .json
		
		// check what thread is currently on
		uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
		Instrumentor::Get().WriteProfile({ m_Name, start, end, threadID});
		
		m_stop = true;
	}
	
private:
	const char* m_Name;
	//std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
	std::chrono::time_point< std::chrono::high_resolution_clock> m_StartTimePoint;
	bool m_stop;
};


//#defiine JOIN_INNER(x, y) x##y
//#define JOIN(x,y) JOIN_INNER(x, y)

// in order to be able to quickly shut on/off the profileing
// Here __FUNCTION__ is a compiler macro. Different for different compilers
// __PRETTY_FUNCTION__ allows to print the signature of the funcion
// also -- compiler dependent
 #define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__PRETTY_FUNCTION__) // __FUNCTION__
#else
#define PROFILE_SCOPE(name)
#endif

namespace BenchMark
{
	void Func1()
	{
		PROFILE_FUNCTION();
		
		for (int i = 0; i< 10000; i++)
		{
			std::cout << "Hi! #" << i << std::endl;
		}
	}

	void Func2()
	{
		
		PROFILE_FUNCTION();
		
		for (int i = 0; i< 10000; i++)
		{
			std::cout << "Hi! #" << sqrt(i) << std::endl;
		}
	}

	void RunBench()
	{
		PROFILE_FUNCTION();
		
		std::cout << "Bench" << std::endl;
		// using lambdas to lauhcn a func on a thread
		std::thread a([]() {Func1(); });
		std::thread b([]() {Func2(); });
		
		// join them so they finish before the end of the scope
		a.join();
		b.join();
		
		
		//Func1();
		//Func2();
	}
}

int main(int argc, char **argv)
{
	Instrumentor::Get().BeginSession("Profile");
	BenchMark::RunBench();
	Instrumentor::Get().EndSession();
	
	return 0;
}
