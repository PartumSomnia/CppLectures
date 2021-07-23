#include <iostream>
#include <string>

/*
 * Initialize a member function insize the constructor
 * 2 ways ti initialize class member
 * 
 * Why use?
 * They are not just for coding
 * 1) for simplicity to see what consturciton is doing
 * 2) functional difference -- in classes -- 
 */ 

class Entity
{
private:
	int m_oc;
	std::string m_Name;
public:
//	Entity()
//	{
//		m_Name = "Unknown";
//		// default construction
//	}
	
	// new constructior that sets the name of the private
//	Entity(const std::string& name)
//	{
//		m_Name = name;
//	}
//	
//	const std::string& GetName() const { return m_Name; }
	
	// new constuctor with member initizalizaiton
	Entity() :
		m_oc(0), m_Name("Uknown")
		// the initialization MUST BE IN ORDER the 
		// variables are defined in class
		{
			//pass
		}
	// construction with member initializaion
	Entity(const std::string& name) : 
		m_oc(1), m_Name(name)
	{
	}
	
	const std::string& GetName() const { return m_Name; }
};


/* Example on the difference 
 * In the following code the class Target() 
 * is initialized TWICE but the first 
 * initialization IMMEDATLY discarded by the 
 * constructor
 * 
 * Member initialization must be used always
 * 
 * */

class Target
{
public:
	Target()
	{
		std::cout << "created a target" << std::endl;
	}
	
	Target(int a)
	{
		std::cout << "Created a target with " << a << std::endl;
	}
};

class Main
{
private:
	Target m_target;
public:
	// construction defauklt
	Main()
	{
		m_target = Target(10);
	}
	
	// construction with member initialization
	// INITILIZE TARGET ONCE
	Main(int x) : 
		m_target(x)
	{
	}
};


int main(int argc, char **argv)
{
	
	Entity e1 = Entity();
	std::cout << e1.GetName() << std::endl;
	
	Entity e2 = Entity("CLASS");
	std::cout << e2.GetName() << std::endl;
	
	
	// bad choice 
	// Main m = Main();
	
	// good choice 
	Main m = Main(10);
	
	return 0;
}
