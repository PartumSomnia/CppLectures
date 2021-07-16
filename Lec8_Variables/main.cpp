#include <stdio.h>
#include <iostream>
/*
 * There 2 types of memory: Stack and Heep 
 * The only dsitiction between primitive datatypes is how much memory they occupy
 * - int  is integer
 * 
 * 1 bite = 8 bit
 * Sign variable -- one bits is used for the sign -- 32 bits for the int number
 * 1 bit for the 2 values -- 2^31 is the value that can be stored == 2B. 
 * 
 * For unsigned int 4.5B is the maximum ONLY positive value.
 *     char, short int long longlong  
 * bite 1      2    4    4     8
 * for integer
 * 
 * Char usually used as characters (letters)
 * 
 * for a decimals: 
 *     float and double
 * bites 4
 * 
 * bool is booling true of false
 * 
 * Im memory only bites can be addres not bits. Then, bool is 4 bits even thogh it is just 1 or 0
 * 
 * check the memory -- sizeof()
 * 
 * creating a point -- adding an asterics to the type
 * 
 */

int main(int argc, char **argv)
{
	int variable = 8; // 4 bites in general compiler, numbers are limited. -2B +2B. Other values require more memory
	std::cout << variable << std::endl;
	variable = 20;
	std::cout << variable << std::endl;
	//printf(variable);

	float variable2 = 5.5f; // this will actually create a double -- f is reqired! 
	std::cout << variable2 << std::endl;

    std::cout << sizeof(variable2) << std::endl; // comiler dependent size of the variable
	
	int* ptr_int = 2; // defining a pointer
	int& ref_int = 2; // defining a reference
	
	return 0;
}
