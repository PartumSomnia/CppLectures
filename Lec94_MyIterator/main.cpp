#include <iostream>
#include "Vector.h"


/*
 * The goal is to implemnet an 
 * iterator into the vector class created in 
 * Lec92_MyVector
 * 
 * We need to implmenet the 
 * - Iterator
 * - begin() // an iterator (pointer) to the first element
 * - end()   // an iterator (pointer) to the memory adress after the last element
 * - !=      // operator that says if we exceed the last element
 * - *it     // pointer to iterator
 * 
 * In the vector class, notably, you don't really need 
 * an iterator. All you do is increment the pointer
 * m_Ptr
 * This however can be implement for any datastructor,
 * but insteasd of ++ being just m_Ptr++; it does 
 * something different, like visiting a 
 * subprocess or subcategory
 * 
 * 
 * 
 */ 

int main(int argc, char **argv)
{
	Vector<std::string> values;
	values.EmplaceBack("Hi ");
	values.EmplaceBack("I ");
	values.EmplaceBack("Am ");
	values.EmplaceBack("Alone ");
	values.EmplaceBack("...");
	
	std::cout << "not using iterator" << std::endl;
	for (int i = 0; i < values.Size(); i++)
	{
		std::cout << values[i] << std::endl;
	}
	
	std::cout << "Range-based for loop\n";
	for (std::string val : values)
		std::cout << val << std::endl;
	
	std::cout << "Iterator\n";
	for (Vector<std::string>::Iterator it = values.begin(); it!=values.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	
	
	return 0;
}
