#include <stdio.h> // preprocess statement (copy the content here)
#include <iostream>


// declaration of the external stuff (promise)
void Log(const char* message); // name of the 


/*
 * 1) preprocess statements with # are run before the code  runs
 *    Files with #include -- are the declarations
 * 2) main() function is the entry point for the application
 *    Lines of code are executed in order. 
 * 3) main() has a return type, but it does not necessarly 
 *    have to return anything. 
 * 4) the << is the overloaded operator (they are like a functions)
 *    << is equivalent cout.print(blabla) 
 * 5) std::cin.get() will wait untill you press enter 
 *    Each .cpp fild is compiled into an object file
 *    Header file are only included.
 *    After compiling, all object files are 'linked' 
 *    via the linker.
 * 
*/


int main(int argc, char **argv)
{
	Log("hello world\n");
	std::cout << "Good by world\n" << std::endl;
	return 0;
}
