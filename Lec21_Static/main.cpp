#include <iostream>

/*
 * 2 meaning of stastic
 * Outside and inside of a class
 * 
 * Stastic outside -- linkage of the symbol is only internal
 * 
 * Static inside -- this object is shared BETWEEN ALL INSTANCESA
 *                  of this class
 * 
 * Here the static is insided only!
 * when linking starts -- only inside this unit the object 
 * will be used
 * 
 * 1. In order to allow for the same var to be defined in 
 *    different .cpp, they MUST be local
 * 2. It is possible to have var defined in one translation
 *    unit and used in another, by defining it in the 
 *    latter as 'extern' -- External
 *    external linking
 * 
 * Static is only visible in different .cpp (not to each other)
 * 
 * Static should be used by default as long as 
 * external usage is not requried.
 * 
 */ 
 
int s_var = 1; // NO error even though it is defined in another .cpp file

// defined in another translation unit and 'imported here'
extern int e_var; //

// same with functions!
void Func()
{
	
}


int main(int argc, char **argv)
{

	std::cout << s_var << std::endl;
	std::cout << e_var << std::endl;
	
	return 0;
}
 