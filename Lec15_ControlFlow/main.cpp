#include <stdio.h>
#include <iostream>


/*
 * continue (only inside the loop -- go to the next)
 * break (get out of the loop)
 * return (get out of the function)
 * 
 */

 
void Log(const char* m)
{
	std::cout << m << std::endl;
}

int main(int argc, char **argv)
{
	
	// continue
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue; // this will skip next lines! 
		
		Log("For");
		
		if ((i + 1) % 2 == 0)
			break; // this will break at the first odd number (1)

		continue; // will not change the behaviour
		
	}
	
	
	return 0;
}
