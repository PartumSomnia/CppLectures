#include <iostream>
#include <string>

/*
 * 
 * Virtual functions allow to overwrite methods in 
 * subclasses
 * Consider classes A and B 
 * B is sublcass of A
 * if a mether in A is a virt.func it can be overritten in B
 * 
 * Virtual functions.
 * Dynamic dispatch
 * Implemented by compilers via V-table -- mapping of 
 * all virtual functions 
 * 
 * Base rule:
 * *To override a function in inhereting class, the base function
 *  must be virtual* 
 * 
 * Virual functions give *Runtime costs* !~
 * 1) Memory for v-table (memer pointer)
 * 2) Every time it is called, the access to v-table is required.
 * But the hit is supposed to be small
 * 
 */

class Entity
{
public:
	std::string GetName() {return "Entity";}
	// generate v-table for this function, in case if is overriten
	virtual std::string GetName2() {return "Entity";}
};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	// constuctor that by takes one param and assigns it to one var
	Player(const std::string& name)
		: m_Name(name) {};

	std::string GetName() { return m_Name; }
	// override is not required, but it helps to see errors
	std::string GetName2() override { return m_Name; }
 
};


int main(int argc, char **argv)
{
	// create pointer to heap allocated instance of the class
	Entity* e = new Entity(); 
	// use method of the calss, accessing through ->
	std::cout << e->GetName() << std::endl;
	
	Entity* p = new Player("Seva");
	std::cout << p->GetName() << std::endl;
	
	/* In the secon case -- you also get Entity
	 * because it is an instance of the Entity, not Player
	 * 
	 * Essencially, when GetName() is called, it 
	 * looks at the Entity, as the pointer of the type 
	 * Entity.
	 * 
	 * In order to have this GetName() "Updated" with the 
	 * new daughter method -- use vertual function
	 * 
	 * */
	
	Player* player = new Player("Seva");
	std::cout << player->GetName() << std::endl;
	// here we get the proper name because the 
	 
	/* Here we consider base func to be VIRTUAL */
	std::cout << e->GetName2() << std::endl; // entity
	std::cout << p->GetName2() << std::endl; // seva
	// this would work because of the dynamic dispatch

	return 0;
	
}
