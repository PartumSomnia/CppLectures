#include <iostream>

/*
 * Statinc in classes and structs
 * 1. static var -- same for ALL isntances of the class 
 *    Should be referred to through the class itself!
 * 2. static method() can be called without class instance
 *    inside you CANNOT write a code tha refers to the 
 *    class instance
 * 3. A static method() can only access the static variable
 *    it existis "withou" instances
 *    It is similar to havgin a method outside of the class
 * 
 * 
 */ 

// example of a normal behaviour
struct Entitiy
{
	int x, y;
	
	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
	
};

// example with a static
struct EntitiyStat
{
	static int x, y;
	
	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
	
	// this will only work if ONLY static variables are inside
	static void StaticPrint()
	{
		std::cout << x << ", " << y << std::endl;
	}
	
};

// define the static variable TO BE VISIBLE outside of the class
int EntitiyStat::x; // Set the scope :: value
int EntitiyStat::y; // without -- linker cannot find x,y


int main(int argc, char **argv)
{
	/* Example of a normal behaviour */
	Entitiy entity;
	entity.x = 2;
	entity.y = 3;
	
	// enother way to initialize a struct
	Entitiy e1 = {5, 8};
	
	entity.Print();
	e1.Print();
	
	std::cout << "--- Using static ---" << std::endl;
	
	
	/* Example with static */
	EntitiyStat entitystat;
	entitystat.x = 2; 
	entitystat.y = 3;
	// For statics this is equivalent to 
	EntitiyStat::x = 2;
	EntitiyStat::y = 3;
		
	// here we actually 
	EntitiyStat entitystat2;
	entitystat2.x = 5; // will not change! 
	entitystat2.y = 8; // This is the same memory! 
	// we modify the EXACT SAME variables
	
	entitystat.Print();
	entitystat2.Print();
	// so this is essencially this:
	EntitiyStat::StaticPrint();
	EntitiyStat::StaticPrint();
	// and this is why the result is the same
	
	return 0;
}
