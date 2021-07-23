#include <iostream>
#include <string>

/*
 * Pure virt func = interface
 * Func that does not have an implementation in the base class
 * 
 * If a function in the base class has a body it may/or may not 
 * be overriten. 
 * 
 * A class that consits of only vertual functions is called 
 * an interface (unimplemented methods)
 * 
 */


class Entity
{
public:
	// here = 0 part implies that it is a PURE VIRTUAL FUNCTION
	virtual std::string GetName() = 0; //{ return "Entity"; } //= 0;//
};

class Player : public Entity
{
private:
	std:: string m_Name;
public:
	Player(const std::string& name)
	: m_Name(name) {}
	
	std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entiry)
{
	// acess the method of the class from a pointer 
	std::cout << entiry->GetName() << std::endl;
}

/*
 * Consider example:
 * You have a func that prints the class name
 * This func takes a pointer on a calss instance that 
 * MUST contain a PrintClassName
 * We introduce the Interface class, that contains a 
 * pure vertual method GetName. This method is 
 * (must be) overiden by other subclasses
 * 
 * The main goal of this is to force a subclass to have
 * an implementation of this virtual function
 * 
 */ 
 
class Interface
{
public:	
	virtual std::string GetClassName() = 0;
};

class SubClass : public Interface
{
public:
	virtual std::string GetClassName() {return "Subclass"; }
};


void PrintClassName(Interface* o)
{
	std::cout << o->GetClassName() << std::endl;
}

int main(int argc, char **argv)
{
	// get a pointer on the instance of the class on the heep
	// Entity* e = new Entity();
	// This will not work for a pure virtual function! 
	
	Player* p = new Player("Me");
	PrintName(p);
	
	
	return 0;
	
}
