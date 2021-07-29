#include <stdio.h>
#include <any>
#include <iostream>
#include <string>

/*
 * Continuation of the trio:
 * std::otional<>()
 * std::variant<>()
 * std::any<>()
 * 
 * Q? Where an why to use it?
 * 
 * variant -- type safe uniuon
 * 
 * any -- for small types -- just a union
 *     -- for a large tupe -- void* big storage 
 *        (dynamically allocated memory)
 * 
 * In practice it is not very intersting
 * 
 */
 


int main(int argc, char **argv)
{
	//std::any data = std::make_any()//
	std::any data;
	data = 2;
	data = std::string("Hi!"); // this is const* char -> error!
	data = 1.f;
	
	
	std::string& str = std::any_cast<std::string&>(data); // might throw exception
	
	return 0;
}
