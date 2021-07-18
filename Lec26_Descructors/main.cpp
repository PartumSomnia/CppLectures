#include <iostream>

/*
 * Desctucor descroys the OBJECT
 * "uninicialize" "free memory"
 * heap and  stack
 * 
 * Stack allocated objects of the calss destryed when 
 * local sope exits (function ends) 
 * 
 * OBJECTS CREATED ON STACK DESTOYED WHEN OUT OF SCOPE
 * 
 * Destructor requires to remove memory leaks 
 * especially when heap allocated memory
 * 
 * Manually one does not call the destructor.
 * 
 */


/* with proper constuctor */
class Entity
{
public:
	float X, Y;
	
	// consturcter must have the same name 
	// does not necessly return anything
	// it sets the variables of the class
	Entity()
	{
		X = 0.f;
		Y = 0.f;
		std::cout << "created object" << std::endl;

	}
	
	Entity(float x, float y)
	{
		X = x; // assign parameter to a member varaible
		Y = y;
	}
	
	// desctructor
	~Entity()
	{
		std::cout << "destroyed object" << std::endl;
	}
	
	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
	
};


void Func()
{
	Entity entity_; // create an instance
	entity_.Print(); // print bulshit becasue is not initiliazed
	
	// desctry instance when exiting the local scope!
	
}

int main(int argc, char **argv)
{

	Func();
	
	return 0;
	
}
