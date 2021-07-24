#include <iostream>
#include <memory>
#include <string>
#include <cstring>

/*
 * 
 * 
 * 
 */ 

class Entity
{
public:
	void Print() const { std::cout << "hi!" << std::endl;}
};


class SmartPrt
{
private:
	Entity* m_Ptr;
public:
	
	SmartPrt(Entity* ptr) 
		: m_Ptr(ptr) {}
	
	
	~SmartPrt(){
		delete m_Ptr;
	}
	
	Entity* operator->() 
	{
		return m_Ptr;
	}
	
	// for const
	const Entity* operator->() const  
	{
		return m_Ptr;
	}
	
};


struct Vector3
{
	float x, y, z;
};

int main(int argc, char **argv)
{
	
	Entity e;
	// calling the meothod of an object
	e.Print();
	
	Entity* ptr_e = &e;
	// calling the method via de-referenicng the pointer
	(*ptr_e).Print();
	// calling the method via arrow (for a pointer)
	ptr_e->Print();
	
	
	/* -- Exmaple with arrow operator overload
	 * to access the object to which the smart 
	 * poiter is pointing on
	 * 
	 */
	
	SmartPrt s_entity = new Entity();
	s_entity->Print();
	// in order to access the Print() of the Entity() 
	// the -> must be overloaded
	// NOTE that m_Ptr is private and that is why -- unnacasible
	
	// automation deleted is automated!
	
	/* ---
	 * Use the arrow to get offset of the memory 
	 * 
	 */ 
	
	// find what is the offset of the variable y
	int offset = (int)&((Vector3*)nullptr)->x;
	std::cout << offset << std::endl;
	
	// this does not work for some reason...//
	
	return 0;
}


