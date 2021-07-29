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
 * C++ is a strongly typed language. 
 * Every variable must have a predifined type
 * Howeve, ther are ways around it -- 
 * such as the 'auto' and explicit/implicit
 * conversions. 
 * 
 * Here we consider explicit/implicit conversions
 * to get "around" the "strong typiness" of C++
 * 
 * "Treat one memory as another memory"
 * Get this type as a pointer and cast into another pointer
 * and de-reference
 * 
 */ 
 
struct Entity 
{
	int x, y;
};
 

int main(int argc, char **argv)
{
	int a = 50;
	// here the 'copy' of a is created of the type double
	double d_a = a;
	// actually, explicitley it reads as 
	double dd_a = (double)a;
	
	// what if we want to use the same memory, but treat it 
	// as a double
	int aa = 50;
	double ddd_a = *(double*)&a; // this type-panning of an integer 
	// into a double
	// BUT! double is bigger -- only 4bytes are initialuzed
	// other 4 bytes -- is not! It did not belong to int
	std::cout << 'Rubish:' << ddd_a << std::endl;
	
	/* --- a better approach --- */
	
	// this -- in memory just 2 integers.
	// the 'struct' does not contain any data
	// we cna treat is as an array<int>
	Entity e = {5, 2};
	
	int* position = (int*)&e; //explicitly converting into array
	std::cout << position[0] << std::endl;
	
	// Raw memory operations -- Important in C++
	
	

	return 0;
}
