#include <iostream>

/*
 * new 
 * is related to memory, performance and optimization
 * 
 * new -- allocation memory on the heep (dynamic allocation)
 * (determining the size)
 * After, the pointer to this memory address is found
 * 
 * All these steps are done for every 'new'
 * 
 * 
 * 
 * 
 * 
 */ 


class Entity
{
private:
	int m_oc;
	std::string m_Name;
public:
	
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


int main(int argc, char **argv)
{
	
	int a = 2;
	int* b = new int; // new allocation on the heep
	*b = 2;
	
	// allocate the memory and call the constuctor
	Entity* e = new Entity("Name");
	
	//usually calling 'new' is equiavelnt
	Entity* ee = (Entity*) malloc(sizeof(Entity));
	// But without calling the constractor! 
	
	delete e; // always delete
	delete ee; // always delete
	
	
	// for arrays:
	double* arr = new double[50];
	delete[] arr;
	
	// requirest where to allocate memoty new(pointer!) 
	
	
	return 0;
}
