#include <iostream>
//#include <string>

/*
 * Strings -- represent text
 * It could be a paragraph and a letter
 * A way to represent is std::string
 * 
 * The text respresenation in C is via 
 * const char* MyString = "hi!";
 * Here 'const' stands for the unchangable.
 * This is because strings in C are unmutable, -- 
 * you cannot change them.
 * 
 * You can define char* Mystring = "hi!";
 * But this might lead to errors.
 * 
 * Strings end with NULL termination pointer, that 
 * is either just 0 or "\0" from the ASCII table.
 * By Default sich NULL already is in "Hi!"; 
 * 
 * C++ strings
 * std::string 
 * is a char array + methods to manipulate them
 * It has a constructor that takes const char* 
 * - .size() // returns size in bytes
 * - .find("string");
 * 
 * Passing into a function:
 * When you do 
 * void Print(std::string mystring){}
 * you are passing the COPY (of the class / object)
 * If you do stdin += "h" inside -- it will not 
 * affect the original string
 * Copyting a string leads to new dynamical allocation 
 * on the heep.
 * 
 * If your string is READ ONLY pass it via const reference
 * 
 */ 

// take a reference -- do not copoy
void PrintString(const std::string& name)
{
	std::cout << name << std::endl;
}

int main(int argc, char **argv)
{
	
	std::string name = "Name";
	std::string another = "My ";
	std::cout << another + name << std::endl;
	std::cout << name << std::endl;
	std::cout << name.size() << std::endl; // size in bytes
	
	PrintString(name);
	
	return 0;
}
