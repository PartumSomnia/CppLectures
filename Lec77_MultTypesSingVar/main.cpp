#include <iostream>
#include <variant>
#include <string>
/*
 * Storring multiple data types 
 * in a single var
 * 
 * std::variant
 * 
 * std::optional<>()
 * std::variant<>()
 * ...
 * continuation of the trope
 * 
 * the std::variant -- 
 * allows not to wary about the exat datarype
 * We list a datatyps that a var can have
 * and then you decide later
 * -- 
 * Create a variable with multiple types
 * 
 * 
 * 
 * 
 * 
 */ 

/* -- practical example
 * 
 * Consider a function that opens a file
 * or does something. 
 * The function returs the result and a statment 
 * whether the operation was successfull
 * This can be done via creating an 
 * enum class ErrorCode 
 * and returiong a varaint from the function as 
 */

enum class ErrorCode
{
	None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, ErrorCode> ReadFile()
{
	// reading file
	// if succesfull return -- 1
	// else -- return -- 2 or something
	return {};
}

int main(int argc, char **argv)
{
	// create a var
	std::variant<std::string, int> data;
	data = std::string("Hi!");
	data = 2;
	// now assign what it CANNOT be
	//data = true; // this cannot be accessed later
	//std::cout << data.index() << std::endl; // -> 1
	
	// check there is a string there?
	// this returns a pointer auto* val = std::get_if<std::string>(&data)
	// if val is null_ptr -- there is not this type
	if ((bool)std::get_if<std::string>(&data))
	{
		// he does not enter! Even though "hi!" is a string!
		// BASTARD!
		//std::string& v = *value;
		std::cout << std::get<std::string>(data) << std::endl;
	}
	//
	std::cout << std::get<int>(data) << std::endl;
	
	/* variants are not type-safe unions */
	
	return 0;
}
