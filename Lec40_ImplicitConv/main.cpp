#include <iostream>
#include <cstring>
#include <string>
/*
 * implicit -- "automatic"
 * "automatically" conver one data type into another
 * 
 * Generally it is to be avoided for 
 * simplicity and readability
 * 
 * 
 * Explicity 
 * put in front of the constructor -- 
 * " do not use the implicity '
 * 
 */ 

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		: m_Name(name), m_Age(-1) {}
	Entity(int age)
		: m_Name("Unknown"), m_Age(age) {}
	explicit Entity(const std::string& name, int age) 
		: m_Name(name), m_Age(age) {}
};

void PrintEntity(const Entity& entity)
{
	//printing
}

int main(int argc, char **argv)
{
	// implicit conversion from 'string' to 'Entity'
	Entity a = std::string("Seva");
	
	// implicitly convert 29 -> Entity(28)
	PrintEntity(28);
	
	
	// PrintEntity("hi!");
	// This does not work because "hi!" is the const char[]
	// Hence, 2 implicit conversions are required here!
	
	
	// can only be used Explicitly
	Entity o_e = Entity("Me", 22);
	
	
	return 0;
}
