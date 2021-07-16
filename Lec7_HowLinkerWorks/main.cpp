#include <stdio.h>
#include <iostream>
#include "log.h"

/*
 * After the source files re compiled, the linking starts: 
 * find all symbols and link them together. 
 * Also, find the enrty point, the main() even for a single file.
 * 
 * Only when you "Build" the compiling AND linking happens.
 * 
 * Error:
 * - Unresolved External Symbol [Underfuked refernece to...]
 *   When linker cannot find the declared function
 *   anywhere else.
 *   If there is no Call to the non-existing BUT decleared funciton, it will not error our.
 * 
 * - If you use 'static' then this function is only used WITHIN this tranlation unit! 
 *   For example static int Multiply(){} will NOT error out if there is undefined call inside
 *   But simple         int Multiply(){} will Error out as it might be called somewhere else
 * 
 * - For linker, both the function name, and return type are important -- func. signature.
 * 
 * - Another Error [multiple definition of]-- 
 *   if there is more than one function with exact same signature.
 * 
 * - Example: Imagine have a Log(){} function in header file, included in two files. Then, 
 *   Linker with error out! In order to avoid it, use static Log(){} that can be used ONLY 
 *   inside this (internal linking)
 * 
 * There is also static and dynamic linking. Not descriebed here
 * 
 */ 

static int Multiply(int a, int b)
{
	Log("multiply");
	return a * b;
}

int main(int argc, char **argv)
{
	std::cout << Multiply(2, 5) << std::endl;
	return 0;
}
