#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple
#include <array>

/*
 * classic standard library for arrays 
 * that do no grow
 * Very similar to noram C array like arr[] 
 * 
 * The C++ supports iterators and sorting
 * and it maintains the size
 * 
 * C++ std::array is strored on the stack
 * It also allows for bounds checking in DEBUG mode
 * (requires Macro)
 * 
 * It is pretty fast (with maximum optimization 
 * possible) 
 * It does not store the size (you define the size
 * and store it yourself)
 * 
 * I could not active the DEBUG array check 
 * the boundaries.
 * One must google it / implement it as a friend ...
 * 
 */ 
 
#define _ITERATOR_DEBUG_LEVEL 2
#define _GLIBCXX_DEBUG true

void PrintArr(int* arr)
{
	
}

int main(int argc, char **argv)
{
	std::array<int, 5> data;
	std::cout << data[0] << std::endl;
	data[6] = 8;
	
	return 0;
}
