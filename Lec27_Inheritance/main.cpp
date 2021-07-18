#include <iostream>

/*
 * Hirarhciy of classes
 * Base calss - common funcs ( parent class )
 * Allows to avoid code duplication
 * by created subclasses 
 * 
 * Class inherits all 'public' methods and variables 
 * 
 * It allows for Polymorphysm
 * -- multiple types for a single type
 * Player always has the same as Entity (plus some)
 * Imagine a function that takes Entity object. 
 * It can also accept Player object as the latter has 
 * the same variables and stuff)
 * 
 * Overriting is possible
 * Enheritance is used all the time
 * 
 *  
 */

// base class with commo functionality
class Entity
{
public:
	
	float X, Y;
	
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};


// child class with specifics
// This maeks Player clas of 2 types -- Player and Entity
// Types in C++ are complex. 
// everything that is not 'private' in Entity is 
// accessible in Player
class Player : public Entity
{
public:
	// additional quanity
	const char* Name;
	
	void PrintName()
	{
		std::cout << Name << std::endl;
	}
	
};


int main(int argc, char **argv)
{
	
	
	std::cout << sizeof(Entity) << std::endl; // 8
	
	Player player1;
	player1.Move(5.f, 5.f);
	
	std::cout << sizeof(player1.Name) << std::endl; // 8?.. not 4..
	std::cout << sizeof(Player) << std::endl; // should be 12...
	
	return 0;
	
}
