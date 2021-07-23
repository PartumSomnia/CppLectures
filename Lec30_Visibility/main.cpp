#include <iostream>

/*
 * Who can see/call methods/variables of the class
 * This does not affect probram run/performance
 * This is the laguage thing to help writing it
 * 
 * Visibility modifiers:
 * private protected private 
 * 
 * Private:
 * Only accessible by THE class and Friend function.
 * Not visible in subclasses!
 * 
 * Protected:
 * Subclasses can see protected!
 *    public methods in subclasses can access it
 * 
 * public:
 * accessed by all :) 
 * 
 * Visiblility is usefull for code development and 
 * maintnence
 * 
 */ 
 

 
class Entity
{
	// only Entity clas can acess 'x' 'y'
private:
	int X, Y;
	
public:
	Entity(){};
	
protected:
	int prX, prY;
	
};


int main(int argc, char **argv)
{
	std::cout << " Pussy! " << std::endl;
	return 0;
}
