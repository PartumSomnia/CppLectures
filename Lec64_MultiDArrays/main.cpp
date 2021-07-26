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
 * Multi-D array is just an array of arryas
 * Collection of arrays
 * Arrays are treated via pointers -- to the beginning of the aray
 * Array of these pointers is a 2D arrays
 * X X ... X
 * . .     .
 * . .     .
 * . .     .
 * where X is a pointer
 * 
 * Allocation of 2D array is not very trivial 
 * Here we use ** -- pointer to a pointer to an integer
 * In fisr allocation -- 50 integers 
 * In the second -- 50 pointers -- very different allocation size
 * 
 * Multy D arrays -- MEMORY FRAGMENTED
 * 
 * Better -- one 'attached' array, with 'smart' access 
 * to the dimensions
 * 
 */ 

int main(int argc, char **argv)
{
	// heap allocated array
	int* array = new int[50]; // 50 * 4 = 200 bytes of memory 
	array[0] = 5; // accessing an integer
	
	// allocate 50 integer pointers
	int** a2d = new int*[50]; // 50 * ? = ??? bytes of memory for POINTERS
	a2d[5] = nullptr; // accessing a pointer!
	
	/* We do not create arrays -- we allocate memory */
	// In both cases the allocated is the same
	
	// Next, now that there is memory --
	// set to each pointer to point at an array
	// we end up with 50 arrays
	
	// here, we assigned each pointer to the heep allocated array
	for (int i = 0; i < 50; i ++) a2d[i] = new int[50];
	
	// accessing the elelemt
	// NOTE [POINTERS][INTEGERS]
	a2d[0][1] = 0;
	
	
	// a 3D array
	int*** a3d = new int**[50]; // allocate 50 pointers to pointers
	for (int i = 0; i < 50; i++) // for each pointer to pointer
	{
		a3d[i] = new int*[50]; // create an array of pointers
		for (int j=0; j<50; j++) // for each of this pointers 
		{						// create an array of integers
			// int** ptr = a3d[j];
			// ptr[j] = new int[50];
			a3d[i][j] = new int[50];
		}
	}
	a3d[0][0][0] = 1; // accessing the element of the array
	
	
	/* ------------- DELETING ------------------ */
	// Loop over all Dunemisions
	for (int i = 0; i < 50; i ++) delete[] a2d[i];
	
	// for 3d:
	for (int i = 0; i < 50; i++)
	{
		for (int j=0; j<50; j++)
		{
			delete[] a3d[i][j];
		}
	}
	
	return 0;
	
	/* --------------------------------------- */
	
	// here we create another 2D array
	// this consits of 5 SEPARATE buffers of 5 integers
	// they are allocated in different places 
	int** b2d = new int*[5];
	for (int i = 0; i < 5; i ++) b2d[i] = new int[5];
	// very inefficient!
	// It is a lot slower then a SINGLE 1D array of 5 * 5 length
	// for optimization it is better to have a 1D array
	
	// consider
	int* d1 = new int[50];
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			d1[x + y * 5] = 2;
		}
	}
	// similar '2d' structure -- x, y -- but much faster
	
	
}
