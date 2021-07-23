#include <iostream>

/*
 * There are several ways to create objects 
 * in C++ 
 * (instanciating)
 * 
 * The choice depends on where (in memory) it should be
 * allocated
 * 
 * the stack and the heep
 * 
 * Stack::automatic lifespan
 * As soon as the variable is out of scope -- memory freed
 * It is usually small though, 1-2 Mb depending on the system
 * For a giant class for for 1000 of them, there might 
 * not be enough space
 * 
 * Heep::once allocated it stays, untill freed manually
 * 
 * allocating on the heep -- longer, required manual deletion
 * 
 */ 

// alias
using String = std::string;


class Entity
{
private:
	String m_Name;
public:
	// constudctors
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}
	
	// getter
	const String& GetName() const { return m_Name; }
};


//void Function()
//{
//	//pass
//}

int main(int argc, char **argv)
{
	
	/* 
	 * the proper way to create on object 
	 * To assure proper memory managment
	 * The fastest/managed way
	 * 
	 * */
	
	Entity entity; // new object (with default construction)
	std::cout << entity.GetName() << std::endl;
	
	Entity entity2 = Entity("New Stack");
	std::cout << entity2.GetName() << std::endl;
	
	/*
	 * If you want the entity to 'live' after the 
	 * function is finished -- stack cannot be used!
	 * 
	 */
	 
	// create a pointer of a type Entity
	// Entity* p_entity;
	
	{
		Entity* p_entity;
		Entity new_entity = Entity("with pointer");
		p_entity = &new_entity; // assign a poiter to de-referneced entity
	}
	// std::cout << p_entity->GetName() << std::endl;
	
	/* 
	 * Creating on the heep requires
	 * 1) a pointer
	 * 2) a 'new' keyword
	 */
	 
	// location on the heep of the object
	Entity* e; // store the memory adress of the new entity
	{
		Entity* p_heep = new Entity("on the heep");
		e = p_heep;
		std::cout << e->GetName() << std::endl;
	}
	// here 'e' still exists and has the name "on the heep"
	// even though the object is out of scope
	std::cout << e->GetName() << std::endl;
	// fogetting delete -- memory leaks
	delete e;
	
	return 0;
}
