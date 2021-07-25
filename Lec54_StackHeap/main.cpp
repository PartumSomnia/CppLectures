#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple

/*
 * Types of memory in C++
 * Stack and heep -- both on RAM
 * Stack is usually 2MB -- predefined
 * Heap can grow during the application
 * 
 * The difference is in how to allocate.
 * How to get a 4bytes, for example, for a new int
 * Memory allocateion
 * 
 * Each time on the stack something is allocated
 * the memory is allocated suquentially.
 * "stacked" on top of each other
 * It is very fast. (moving the stack pointer)
 * After the scope is concluded the momory is freed
 * and the 'stack' pointer jumps back, to use it for 
 * other {} 
 * 
 * In the heep allocation -- memory is allocated 
 * whenever is available -- usually in random places
 * Read/write from it is lengthy
 * Do not forget to manually delete 
 * 
 * word 'new' calls malloc() function to allocate the 
 * memory and it is regested in a 'free list' 
 * that contains the free memory parts
 * ''' book-keeping '''
 * malloc() is a heavy function
 * 
 * The slow part is calling 'new' and searching for 
 * this memory. 
 * After, its use is basically the same as heep
 * (provided it is prperly allocated as a one cosequet chank)
 * 
 * 
 * 
 */ 

struct Vec
{
	float x, y, z;
	
	Vec()
		: x(10.), y(11.), z(12.) {}
	
	Vec(float x, float y, float z)
		: x(x), y(y), z(z) {}
};

int main(int argc, char **argv)
{
	
	// allocating the stack
	int val = 5;
	
	// allocated on heep
	int* hvalue = new int; *hvalue = 2;
	
	// allocatng an array
	int arr[5];
	for (int i=0; i<5; i++) arr[i] = i;
	int* harr = new int[5];
	for (int i=0; i<5; i++) harr[i] = i;
	
	for (int i=0; i<5; i++) std::cout << harr[i] << std::endl;
	
	// allocating 
	Vec vec = Vec({1.,2.,3.});
	Vec* hvec = new Vec;
	*hvec = Vec({1.,2.,3.});
	
	delete hvalue;
	delete[] harr;
	delete hvec;
	
	return 0;
}
