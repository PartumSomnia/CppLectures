#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple
#include <array>
#include <algorithm> // for findif

/*
 * 'C' does not have namesapces
 * 
 * Avoid naming conflicts -- the main purpose
 * 
 * You can define nested namespaces
 * 
 * one can do 
 * using namespace std
 * or Name1
 * to "import" everyting from a given namespace
 * 
 */

namespace Name1
{
	void Print(int a)
	{
		std::cout << a << std::endl;
	}
	
	namespace NName1
	{
		void Print(float a)
		{
			std::cout << a << std::endl;
		} 
	}
	
} 

namespace Name2
{
	void Print(int a, int b)
	{
		std::cout << a << b << std::endl;
	}
}

int main(int argc, char **argv)
{
	
	// stupid, but you can do that :) 
	Name1::Print(1);
	Name1::NName1::Print(1.2);
	Name2::Print(2,3);
	
	return 0;
}
