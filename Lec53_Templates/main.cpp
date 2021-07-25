#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple

/*
 * Templates are similar to 'macro'
 * A template allows to define an object that will 
 * compiled based on rules you define -- compliler will 
 * write a code for it.
 * 
 * Example -- function is the same but take 
 * different types
 * 
 * Template DOES NOT exists untill called!
 * 
 * Templtes are used for classes and funcs
 * 
 * Templates can escalate a lot.
 * Sometimes they are not too usefull. 
 * They obscure code. 
 * 
 */ 

// templated
// All overloads for different types are "created" by complier 
// at compilation
template<typename t> // here also class can be used instead of 'typename'
void Func(t var)
{
	std::cout << var << std::endl;
}

// example of the class array that we want to 
// be located on the stack not on the heep
// both the type of data and the size of an array 
// are determined at compile time 
template<typename t, int size>
class Array
{
private:
	t m_Array[size];
public:
	int getSize() const { return size; }
};


int main(int argc, char **argv)
{

	// here the type is inferred 'implicitley'
	Func("Hi!");
	Func(1.5);
	Func(1);
	
	// the type can be set explicitly
	Func<int>(2);
	
	
	// use the stack array class with the size determined ad compile time
	Array<int,5> array;
	
	return 0;
}
