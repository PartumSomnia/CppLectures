#include <iostream>

/*
 * The keyword " this " 
 * is only accessable by member function
 * 
 * This -- is a pointer to the currect object instanced
 * 
 * Use a function from within the class that is outside the 
 * class, passing the class as a paramter
 * 
 * ! here I could not replicate the behaviour with the function
 * PrintEntity() 
 * Error with definition of Entity() 
 * which is defined below... 
 * 
 * Could not solve
 * 
 * 
 */ 

// void PrintEntity(Entity* e);

class Entity
{
	int x, y;
public:
	Entity(int x, int y) 
	{
		// essencially the follwoing 
		this->x = x;
		this->y = y;
		// is equivalent to 
		// Entity* const e = this; // now allowed to be reassiged
		// e->x = x;
		// e->y = y;
		
		//PrintEntity(this);// this is the pointer o
		
		// delete this; // 
	}
	int GetX() const
	{
		// must be const so that you cannot mofify the pointer
		// const Entity* e = this;
		return x;
		
	}
 
};

void PrintEntity(Entity* e)
{
	pass
}

int main(int argc, char **argv)
{
	
	return 0;
}
