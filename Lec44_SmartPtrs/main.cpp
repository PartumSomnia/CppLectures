#include <iostream>
#include <memory>

/*
 * Smart pointer -- 
 * 
 * Recall new and delete for heep
 * smart pointers allow to automate this 
 * new/delete procedure
 * Smart pointer is a wrapper around a 
 * classical pointer
 * 
 * A unique pointer -- scoper pointer
 * Copying unique pointer cannot be done
 * 
 * For heep allocated objects
 * 
 * Unique pointers :: only within the scope. One!
 * Shared pointers :: exists if 1+ copy exists
 * Weak pointer :: like shared, but des not + to the count
 * 
 */ 

class Entity
{
private:
	int x, y; // allocated on the stack
public:
	Entity()
	{
		std::cout << "Created " << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed " << std::endl;
	}
	
	void Print() {}
};


int main(int argc, char **argv)
{
	
	{
		std::shared_ptr<Entity> p_esh;
		{
			// using unique pointer
			// templated for Entity, 
			// using EXPLICIT construction
			/* std::unique_ptr<Entity> entity(new Entity()); */
			// a proper way however is 
			std::unique_ptr<Entity> entity = std::make_unique<Entity>();
			// this is for exceptions safety
			
			/*
			 * Note that here the class object is created on the 
			 * heep. -- Can live outside of the cope.
			 * But becasue of the 'smart pointer' -- unique one
			 * it will be automatically destroyed upon leaving the scope
			 * Important ! You cannot copy it (pass it into function)
			 * 
			 */
			 
			// Shared pointer 
			// Reference counting
			// keep counting on how many references 
			// as soon as there is 0 -- it is deleted
			// allocate another block of memory -- memory count with make shared
			std::shared_ptr<Entity> shared_ptr = std::make_shared<Entity>();
			p_esh = shared_ptr;// creating a copy
			
			// will not increase the count of pointers
			std::weak_ptr<Entity> weak_ptr = shared_ptr;
			
		}
		// here only 'p_esh' is alive. Hence, the class is not destroyed!
		// here shared entuty is still alive!
	}
	// here 'p_esh' also dies, as all the references are gone
	// when all stack allocated 
	
	return 0;
}
