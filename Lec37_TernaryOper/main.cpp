#include <iostream>
#include <string>


/*
 * Ternary operations -- ?:
 * in the middle of the code 
 * This is -- alias for if statement
 * 
 */ 
 
static int s_Level = 1;
static int s_Speed = 2;

int main(int argc, char **argv)
{
	
	// this is essencially conditional assignemnt
	if (s_Level > 5)
	{
		s_Speed = 10;
	} else {
		s_Speed = 5;
	}
	
	std::cout << s_Speed << std::endl;
	
	// ternary operator :: conditional assignemnt
	s_Speed = s_Level > 5 ? 10 : 5;
	
	std::cout << s_Speed << std::endl;
	
	// nesting 
	s_Speed = s_Level > 10 ? s_Level > 15 ? -1 : 0 : 1;
	
	std::cout << s_Speed << std::endl;
	
	return 0;
}
