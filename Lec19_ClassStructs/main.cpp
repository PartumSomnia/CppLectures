#include <iostream>

/*
 * Difference between classes and structs
 * Difference is only in visibility
 * Class has private variables by default
 * Struct is public by default 
 * All other functionality is the same!
 * 
 * Difference is in usage.
 * Struct exists for backwards compatibility with C
 * 
 * Structs are used when only variables are represented
 * e.g., mathematical vector class
 * 
 * Inheritance is usually used in classes, not with structs
 * 
 */ 

#define LOG(x) std::cout << x << std::endl;

// just a container for variables
struct vec2
{
	float x, y; // only two public variables
	
	// 'add' method for a vector (component-vise)
	// pass a reference to another instance of the same class
	void Add(const vec2& other)
	{
		x += other.x;
		y += other.y;
	}
	
};



int main(int argc, char **argv)
{
	
	
	
	return 0;
}
