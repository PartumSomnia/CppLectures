#include <iostream>

/*
 * Constructor - special method run when object in istanced
 * 
 * Constucter always exists ; but it does not do anything
 * Manyally varaibles have to initialized.
 * 
 * Class has to be instanceated to use constractor
 * 
 * A class with ONLY static methods can 
 * be used with no constractors.
 * Constructor can be PRIVATE
 * 
 * Log() = delete
 * will remove the constructor
 * 
 * 
 */

/* No constuctor et all */
class Entity
{
public:
	float X, Y;
	
	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
	
};

/* with 'by hand' constuctor */
class EntityI
{
public:
	float X, Y;
	
	void Init()
	{
		X = 0;
		Y = 0;
	}
	
	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
	
};

/* with proper constuctor */
class EntityII
{
public:
	float X, Y;
	
	// consturcter must have the same name 
	// does not necessly return anything
	// it sets the variables of the class
	EntityII()
	{
		X = 0.f;
		Y = 0.f;
	}
	
	EntityII(float x, float y)
	{
		X = x; // assign parameter to a member varaible
		Y = y;
	}
	
	
	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
	
};

int main(int argc, char **argv)
{

	// print un-initialized values
	Entity entity;
	entity.Print(); // print bulshit becasue is not initiliazed
	
	// print Inititialized (externally) values
	EntityI entityI;
	entityI.Init();
	entityI.Print(); // print bulshit becasue is not initiliazed
	
	// print Inititialized properly values
	EntityII entityII;
	entityII.Print(); // print bulshit becasue is not initiliazed
	
		// print Inititialized properly values
	EntityII entityII_(10.f, 5.f);
	entityII_.Print(); // print bulshit becasue is not initiliazed
	
	
	return 0;
	
}
