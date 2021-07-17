#include <stdio.h>
#include <iostream>
/*
 * For an while loops.
 * 
 * 
 */

void Log(const char* m)
{
	std::cout << m << std::endl;
}

int main(int argc, char **argv)
{
	Log("Hi, bro!");
	
	// iterator; condition; code BEFORE next iteration
	for (int i = 0; i < 5; i++)
	{
		Log("for");
	}
	
	// coditions can be set separately
	int i = 0;
		for (; i < 5; )
	{
		Log("for 2");
		i++;
	}
	
	// while loop
	while (i < 10)
	{
		Log("While...");
		i++;
	}
	
	// one more loop
	do
	{
		Log("do while");
		i++;
	} while (i < 15);
	
	
	return 0;
}
