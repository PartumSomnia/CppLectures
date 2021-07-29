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
 * Unions is a struct-like object that can 
 * occupy only one variable size
 * Union can have only ONE member
 * 
 * Unions are used to type-punning
 * (See Lec66)
 * 
 * E.g. two different names for the same variable
 * Like x.y.z -> R.G.B
 * 
 * They are used anonymously
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 
 
struct Vector2
{
	float x, y;
};

struct Vector4
{	
	//float x, y, z, w;
	
    union // anonymos
	{
		struct // no name -- just a way to structre data
		{
			float x, y, z, w;
		};
		
		// this will occupy the same memory
		struct 
		{
			//      x y  z w
			Vector2 a,   b;
		};
	};
};
 
void PrintVector(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}
 

int main(int argc, char **argv)
{
	// two ways to adress the same memory
	// Wrap it into a class for easy acess
	struct Union
	{
		union 
		{
			float a;
			int b;
		};
		
	};
	
	Union u;
	u.a = 2.0f;
	std::cout << u.a << ", " << u.b << std::endl;
	// we get two results but THEY ARE THE SAME 2.0f
	// just written as a int and as a float
	
	
	/* -- consider example with Vector 2 and Vector 4 -- */
	
	// we have a way to print Vector2 but not Vector4
	// How to do that without creating a new object
	// using the reference to Vector 2 
	
	// This can be done via union 
	// So. In order to be able to use 
	// Vector2 to print Vector4, we 
	// use anonymons union. Since it can 
	// only have one element -- we wrap all four 
	// varaibles of the Vector4 into an 
	// anonymous struct as 
	// the accessing is still the same 
	
	Vector4 vec4 = {1.f, 2.f, 3.f, 4.f};
	std::cout << vec4.w << std::endl;
	
	PrintVector(vec4.a);
	PrintVector(vec4.b);
	
	vec4.z = 500.f;
	std::cout << " ----------- " << std::endl;
	
	PrintVector(vec4.a);
	PrintVector(vec4.b);
	
	return 0;
}
