#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple

#define DEBUG true

// better Macros
#if DEBUG
#define LOGDEBUG(x) std::cout << x << std::endl
#else
#define LOGDEBUG(x)
#endif

/*
 * auto infers the type from RHS
 * If you change the return value 
 * the code in main() automatically adjusts!
 * 
 * auto can shorten long types
 * 
 */ 

std::string GetName()
{
	return "Name:)";
}


int main(int argc, char **argv)
{
	
	auto x = 5;
	auto y = "hi!";
	
	LOGDEBUG(x);
	LOGDEBUG(y);
	
	LOGDEBUG("Beguggggging:)");
	
	auto name = GetName();
	
	
	return 0;
}
