#include <iostream>
#include <memory>
#include <chrono>
#include <array>

/*
 * There are many ways to benchmark a code
 * Here we consider a scoped-based timer class
 * It starts the clock at initialization 
 * and strops and distruction (end of the scope).
 * 
 * It is important to understand what the timer 
 * measures, as the compiler tends to change/optimize
 * the code
 * 
 * 
 * 
 * 
 */ 

// writing simple scoped based timer
// creating timer
class Timer
{
public:
	/* Resource acuisoton and initialization */
	Timer()
	{
		// get current time
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}
	
	~Timer()
	{
		Stop();
	}
	
	void Stop()
	{
		auto m_EndTimePoint = std::chrono::high_resolution_clock::now();
		// get time since the berin and cast it into microseconds
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch();
		// same for the end time
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_EndTimePoint).time_since_epoch();
		// compute duration
		auto duration = end - start;
		double time = std::chrono::duration<double>(duration).count();
		double time_ms = time * 0.001;
		
		std::cout << "Time: " << time << "us (" << time_ms << "ms)\n";

	}
	
private:
	// store time in a private variable
	std::chrono::time_point< std::chrono::high_resolution_clock> m_StartTimePoint;
	std::chrono::time_point< std::chrono::high_resolution_clock> m_EndTimePoint;

};

int main(int argc, char **argv)
{
	int value = 0;
	{
	    // here we actually timing the +2 in Debug
		// In release -- compiler realized tha all 
		// of this can be optimized at compile time
		// NO +2 was done! Only cout! 
		
		Timer timer;
		
		for (int i = 0; i < 10000000; i++)
			value += 2;
		std::cout << value << std::endl;
	}
	
	
	// let us measure the overhead from 
	// using the smart pointers
	std::cout << "Make Shared\n";
	{
		Timer timer;
		struct Vector2
		{
			float x, y;
		};
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}
	// here we compre with 
	std::cout << "New Shared\n";
	{
		Timer timer;
		struct Vector2
		{
			float x, y;
		};
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}
	// here we compre with unique
	std::cout << "Make Unique\n";
	{
		Timer timer;
		struct Vector2
		{
			float x, y;
		};
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_unique<Vector2>();
	}
	
	
	/*
	 * DO NOT PROFILE IT IN DEBUG MODE!
	 * USE RELEASE MODE WITH REQUIRED OPTIMIZTION
	 * 
	 */ 
	
	return 0;
}
