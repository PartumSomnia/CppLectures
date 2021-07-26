#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple
#include <array>

/*
 * Here we consider raw way -- from C
 * 'raw function pointer'
 * Function pointers -- assign a function
 * to a variable
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 

void Hello()
{
	std::cout << "Hi!" << std::endl;
}

void Print(int a)
{
	std::cout << "Hi!" << a << std::endl;
}

// pass a function as a pointer into another function
void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values) func(value);
}

int main(int argc, char **argv)
{
	//get a pointer to the function
	auto func = Hello; // here we get the memory address
	// ampersant is not needed
	
	func();
	func(); // tupe void(*function)
	
	// this is the type of the actual function
	void(*ffunc)() = Hello;

	// here the 'auto' is usually preverred
	// or a typedef void(*func)();
	// 
	
	auto print = Print;
	
	print(2);
	print(10);
	
	
	// where it is used?
	// consider a vector
	
	std::vector<int> values = {1, 2, 3, 4, 5};
	ForEach(values, Print);
	
	// to simplify this code we can use a lambda function
	// lambda is an anonymos function
	Lambda(values, [](int value) {std::cout << "Hi!" << a << std::endl; });
	// does not work for some reason...
	
	return 0;
}
