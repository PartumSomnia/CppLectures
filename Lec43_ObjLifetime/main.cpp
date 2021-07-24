#include <iostream>

/*
 * Object lifetime
 * Objects living on stack
 * 
 * 1. Understand how things live on the stack
 * 2. How to imporve/smart things
 * 
 * Stack is the datastructire with data on top of each other 
 * Like adding a book on the pile
 * Every new object is like pages in the book
 * once the skope ends -- entrie book is delete 
 *
 * Skopes are 
 * func() { } 
 * 
 * Classes { };
 * 
 * Just empty scopes with { }
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
	
	
};

// smart pointer examples (scope pointer)
// stors the pointer upon construciton
// deletes it automatically when is 
// desctructed 
// 
class ScopedPoiter
{
private:
	Entity* m_Ptr;
public:
	ScopedPoiter(Entity* ptr)
		: m_Ptr(ptr) {}
	~ScopedPoiter()
	{
		delete m_Ptr;
	}
};

int main(int argc, char **argv)
{
	{
		// creating on the stack
		Entity e_stack;
		Entity* p_e_heep = new Entity; // This will not be descroyed
		ScopedPoiter e = new Entity();
	}// at this point the 'e_stack' is desctoryed
	
	
	
	// e_heep is not destroyed untill the end of the code
	return 0; 
}
