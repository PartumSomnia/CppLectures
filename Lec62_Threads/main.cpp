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
//#include <pthread.h>

/*
 * how to write a code that consideres several
 * threads? 
 * Different works -- for different threads of execution
 * e.g., std::cin.get() can wait while other 
 * threads do the work, like saving/logging/...
 * 
 * NOTE @ You must include 
 * 1) properties >> c/c++Build >> setting >> GCC C++ linker >> libraries
 * 2) Add -pthread at the top.
 * In the project properties! Otherwise you gen a 'build failed' error!
 * 
 * 
 * 
 */ 

static bool s_finished = true;

void Task()
{
	// for time writtin in '4s'
	using namespace std::literals::chrono_literals;
	
	while(s_finished)
	{
		// This will result in a 100% CPU usage 
		std::cout << "printing" << std::endl;
		
		std::this_thread::sleep_for(4s);
		
	}
}

int main(int argc, char **argv)
{
	
	std::thread worker(Task); // this thread is just printing stuff
	
	// this thread is waiting for us to press the enter
	std::cin.get();
	// after we do the bool changes -- and alters the behaviour of the 
	// other thread
	s_finished = false;
	
	// after thre
	// thread joining is a complex object -- similar to 'wait'
	worker.join();
	
	
	return 0;
}
