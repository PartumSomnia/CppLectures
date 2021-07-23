#include <iostream>

/*
 * Array -- represents a collection of variables
 * Collection of data
 * 
 * Array[] in C++ is really just a pointer to the 
 * memory, where the data is store continously, every N byte,
 * where N is the size of the one eleemnt of the array
 * 
 * Arrays always used in for loops
 * 
 * Arrays store data conticously -- in a row, one after another!
 * Very efficient for read/write!
 * 
 * Array on the "stack" are destroyed when {} is finished 
 * where they defined
 * Arrays on the heep are alived UNTILL DESTROYED MANUALLY or 
 * untill the program ends
 * 
 * anything with "new" has to be remuved manually
 * Arrays are better to be defined on the stack for 
 * memory accessability ease.
 * 
 * 
 * In C++11 there is a std::array() 
 * It has many andvantages incl. size of the araray
 * 
 * In C++ there is no "simple" way to know how 
 * much memory it occupies (IF IT IS ON THE HEEP). 
 * The std::array() does contain the size
 * If an array is on the STACK there is sizeof()
 */ 

int main(int argc, char **argv)
{
	
	// define array
	int example[5]; // allocate space for 5 integers 
	// access the element
	example[0] = 2;
	// show
	std::cout << example[0] << std::endl;
	
	// Note example[5] is not valied! This access memory that 
	// MEMORY ACESS VIOLATION -- only in DEBUG mode
	// is not allocated for this array
	
	std::cout << example << std::endl; // print the memory address
	
	// using for loop to assigne values
	for (int i = 0; i < 5; i++)
		example[i] = i;
	
	// using 4 loop in
	for (int i = 0; i < 5; i++)
		std::cout << example[i] << std::endl;
	
	// ways to access the element :
	example[2] = 10; // standard acess
	int* ptr = example; // creating a pointer
	*(ptr + 3) = 11; // dereferncing the pointer (3rd position)
					 // adding 3 * 4 bytes (where 4 is the size of int) 
	std::cout << example[2] << std::endl;// 10
	std::cout << example[3] << std::endl;// 11
	std::cout << "Size of the Array:" << sizeof(example) << std::endl;
	std::cout << "Number of elements:" << sizeof(example)/sizeof(int) << std::endl;
	
	
	// arrays can also be created on the heep 
	// dynamic allocation
	// here there is an idirect allocation -- 
	// essencially you create a place in memory that stores the 
	// adress of your actual data
	int* another = new int[5]; 
	for (int i = 0; i < 5; i++)
		another[i] = i;
	for (int i = 0; i < 5; i++)
		std::cout << another[i] << std::endl;
	delete[] another; // delete an array
	
	
	// the size of the array has to be known at compile time
	// this can be achieved with static! 
	static const int sizeOfArray = 5;
	int newarray[sizeOfArray];

	
	printf("hello world\n");
	return 0;
}
