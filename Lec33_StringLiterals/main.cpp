#include <iostream>
#include <cstring> // for strlen()
#include <stdlib.h>

/*
 * String literal -- string of character in betwee " and " :) 
 * "Hi!";
 * is a const char[4]
 * where 4 is because of the Null termination in the end
 * 
 * Note string is a const char* 
 * YOu cannot change it,
 * If you try :
 * 
 * char* name = "hi!"
 * name[0] = "H";
 * 
 * you get an UDEFINE behaviour
 * 
 */ 

int main(int argc, char **argv)
{
	// as soon as \0 is hit the 
	const char example[6] = "Se\0va";
	std::cout << strlen(example) << std::endl;
	
	const char* string1 = u8"char 1 byte per character";
	const wchar_t* string2 = L"wide string 2 bytes";
	const char16_t* string3 = u"char16_t 2 bytes per character";
	const char32_t* string4 = U"char32_t 4 bytes per character";
	
	// in c++ 14
	using namespace std::string_literals;
	
	// 's' -> returns the constructor of the string!
	// allows to do this procedure with strings!
	std::string name0 = "My "s + "Name";
	
	// for multiline strings add R"" to the string (R stands for raw
	const char* longline = R"(:Line1 
	Line2
	Line3)";
	
	
	// strings are always stored in READ-ONLY memory
	
	return 0;
}
