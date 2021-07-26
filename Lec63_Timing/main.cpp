#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple
#include <array>
#include <algorithm> // for findif
#include <thread>
#include <chrono>
#include <typeinfo>
/*
 * Since C++11 the ability to time functions and 
 * pieces of code are available by default here
 * thorugh the chrono library
 * 
 * 
 * Example: use the object lifetime 
 * to count how long the piece of code took
 * 
 * 
 */ 

struct Timer
{
	//std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::system_clock::time_point start, end;
	std::chrono::duration<float> duration;
	
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end-start; // duration in seconds
		float duration_ms = duration.count() * 1000.0f;
		std::cout << "Time took " << duration_ms << " ms" << std::endl;
	}
	
};

void Function()
{
	
	Timer timer;
	
	for (int i = 0; i<100; i++)
		std::cout << "Hellow" << std::endl;
}

void Example1()
{
	using namespace std::literals::chrono_literals;
	auto start = std::chrono::high_resolution_clock::now();
	//int x = 1;
	//std::cout << typeid(start).name() << std::endl;
	std::string my_type = typeid(start).name();
	system(("echo " + my_type + " | c++filt -t").c_str());
	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << "s " << std::endl;
	
}


int main(int argc, char **argv)
{
	//Example1();
	
	Function();
	
	return 0;
}
