#include <iostream>

/*
 * Operator (instead of function) to perform an 
 * operation
 * &, *, >>, <<, etc
 * new, delete
 * ',' () 
 * 
 * Operator overloading -- give a new meaning to oper.
 * Define/change the behaviour
 * 
 * Operators are just functions 
 * Help read/write code
 * 
 * 
 */ 

struct Vector2
{
	float x, y;
	
	Vector2(float x, float y) 
		: x(x), y(y) {}
		
	// external methods to add two objects
	Vector2 Add(const Vector2& other) const 
	{
		//return Vector2(x + other.x, y + other.y);
		
		// using the overload 
		// dereference the const pointer and add with other
		return *this + other;
	}
	
	Vector2 Multiply(const Vector2& other) const 
	{
		return Vector2(x * other.x, y * other.y);
	}
	
	
	// operator overloading
	// define operator on the class Vector2
	// that overloads '+'
	// and takes another Vector2 object by reference
	// and is const 
	Vector2 operator+(const Vector2& other) const 
	{
		return Vector2(x + other.x, y + other.y);
	}
	
};


// add to cout an overload :: overload << of the osream 
// std::ostream& -- original definition of the <<
// operator<< -- is what we want to overaload
// pass the reference to the class -- stream
// pass for what you want to use it for -- other
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	std::cout << other.x << ", " << other.y << std::endl;
	return stream;
	
}


int main(int argc, char **argv)
{
	Vector2 position(4.f, 4.f);
	Vector2 speed(.5f, .5f);
	Vector2 powerup(1.1f, 1.1f);
	
	Vector2 result = position.Add(speed);
	
	// Now this is possible via overloading '+'
	Vector2 result2 = position + speed;
	
	// what if we want to print the vecotr:
	std::cout << result2 << std::endl;
	
	return 0;
}
