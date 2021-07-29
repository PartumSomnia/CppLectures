#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple
#include <array>
#include <algorithm> // for findif
#include <thread>
#include <chrono>
#include <typeinfo>

/*
 * conversions within type system
 * C++ is strongly typed language
 * Types are inforced
 * There are implicity and explicit conversions
 * This can be done via "type panning"
 * 
 * Type conversions are done in 2 ways
 * - C style case
 * - C++ cast
 * 
 * 
 * 
 */ 


class Base
{
public:
	
	Base() { std::cout << "Base constructed " << std::endl; } 
	virtual ~Base() { std::cout << "Base distructed " << std::endl; } 
};


class Derived : public Base
{
public:
	
	Derived() { std::cout << "Derived constructed " << std::endl; } 
	~Derived() { std::cout << "Derived distructed " << std::endl; } 
};

class Another : public Base
{
public:
	Another(){ }
	~Another(){ }
};

int main(int argc, char **argv)
{
	
	int a = 5;
	// here the implicit conversion can take place
	double value = a;
	// same here
	double val = 5.25;
	int b = val;
	
	// explicit casting is 
	int _b = (int)value;
	std::cout << _b << std::endl;
	
	// the 
	int cpp_a = 2;
	double cpp_b = static_cast<int>(cpp_a);
	
	/*
	 * there are:
	 * - static_cast 
	 * - reinteprete_cast	// similar to punning,
	 * - dynamic_cast       // check (performance overhead)
	 * - const_cast			// add/remove cast
	 * 
	 * But the actual conversion is the same as 
	 * C style cast
	 * It adds a syntax shuger to the code
	 * 
	 * 
	 * 
	 */ 
	 
	// dynamic cast 
	
	Derived* derived = new Derived();
	Base* base = new Base();
	// if we do not know if the second is also an instance 
	// of the former we can try to cast it 
	
	Another* ac = dynamic_cast<Another*>(base);
	if (!ac)
	{
		// a way to check if cast was successfull
		std::cout << " not correct class " << std::endl;
		// BUT THIS TAKES TIME -- runtime checking
	}
	// this workds for any cast:: static, dynamic, or C
	
	
	
	return 0;
}
