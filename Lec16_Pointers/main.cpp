#include <stdio.h>
#include <iostream>
#include <cstring> // for the memset
/*
 * Raw pointers
 * Long metafora about houses on the street, with each house 
 * being a byte of memory.
 * Pointer is the adress in memory.
 * 
 * Pointer itself does not need a type.
 * Type usually specifies what variable it stores. 
 * 
 * POINTERS ARE INTEGERS THAT STORE MEMORY ADRESS
 * 
 */ 

// another way to defile a function 
#define LOG(x) std::cout << x << std::endl;
//void Log(const char* m)
//{
//	std::cout << m << std::endl;
//}


int main(int argc, char **argv)
{
	
	/*  --- HERE WE ARE WORKING WITH THE STACK POTION OF THE MEMORY --- */
	
	// typeless pointer 
	void* ptr = nullptr; // 0 is not valid memory adress
	
	// this var has a memory adress
	int var = 8;
	// get memory adress of var and assign it to the pointer
	void* ptr_var = &var; // holds now the memory adress of the integer 
	
	// in order to writ to/ read from data using the pointer, -- use dereferncing
	//*ptr = 10;// accessing the data BUT for void point IT will NOT work. 
	
	int var2 = 10; // create a variable
	int* prt_var2 = &var2; // create a pointer to the value
	*prt_var2 = 20;// here it is allowed because pointer is meant to store int value -- can be reassigned
	
	LOG(*prt_var2); // here the de-referencing is used to acess the value
	
	
	/* --- CONSIDER MEMOY ON THE HEAP --- */
	// allocated 8 bytes of the char
	char* buffer = new char[8]; // allocate 8 bytes of memory and return a pointer to the beginning
	memset(buffer, 0, 8); // fill the buffer with 0 using 8 bytes.
	
	/* --- pointers to pointers -- */
	// pointers are just variables that also occupy memory 
	char** prt = &buffer;
	
	return 0;
}
