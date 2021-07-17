#include <stdio.h>
#include <iostream>
/*
 * Condition statements (if, else, etc)
 * if statement does -- evaluateion of thecondition and 
 * brach selectrion and execution (branch to one set 
 * of CPU instraction or another)
 * All instructions are stored in memory. 
 * If -- makes code jump in memory (to a new instruction)
 * Overhead is given by the if statement, branching. 
 * Optimized code removes branches.
 * 
 * if () {} else {}
 * 
 * 
 * 
 */

void Log(const char* m)
{
	std::cout << m << std::endl;
}

int main(int argc, char **argv)
{
	
	int x = 5;
	bool res = x == 5; // using equality operator (bit by bit compare)
	if (res)
	{
		std::cout << "x = 5" << std::endl;
	}
	
	const char* ptr = nullptr;
	if (ptr)
		Log("pointer is True");
	else if (ptr == "Hi")
		Log("pointer sais hi");
	else
		Log("pointer is Null");
	
	printf("hello world\n");
	return 0;
}
