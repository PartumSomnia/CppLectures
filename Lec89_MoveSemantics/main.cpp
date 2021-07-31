#include <iostream>
#include <string>
#include <cstring>
/*
 * Move allows to move objects around without copying them 
 * For example, if an object is passed int oa func 
 * that takes its ownership, -- there only copy.
 * But since C++11 it is possible to "move" it into 
 * the function
 * 
 * Here we consider 2 classes 
 * The object of a String is instanciated first 
 * but then passed into another class
 * The Goal is to make the 'pass' withou copying
 * This si achieved by creating a new "move" constructor 
 * in String(){} that takes an r-value only, i.e., value&&
 * and instead of copying it it copies THE POINTER to it 
 * and delets the previos object by setting it to nullptr.
 * 
 * The final piece is in the Entity constructor
 * Instead of calling Var(var) you cast it into 
 * Var((String&&)var), -- making the passed argiment a r-value
 * 
 * This allows for code optimization, as data has not 
 * been copied -- no new allocations have been done
 * 
 * 
 */ 

class String
{
public:
	// default constructor
	String() = default;
	// constructor
	String(const char* string)
	{
		printf("created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	// deep-copy
	String(const String& other)
	{
		printf("copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}
	
	// shallow-copy
	String(String&& other) noexcept// not supposed to be throwing exceptions
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data; // re-assigning a pointer
		//memcpy(m_Data, other.m_Data, m_Size); // no memory 
		
		// get rid of the previous instance
		other.m_Size = 0;
		other.m_Data = nullptr; // so that Descturctor does not 
		// destroy our "relocated" object
	}
	
	~String()
	{
		printf("Destryd!\n");
		delete m_Data;
	}
	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++ )
			printf("%c", m_Data[i]);
		printf("\n");
	}
	
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	// general constructor
	Entity(const String& name)
		: m_Name(name) {}
	
	// constructor that takes a temporary (for r-value)
	Entity(String&& name)
		: m_Name((String&&)name) {} // here the copy still happns! -> cast it into temporary
	
	void PrintName() { m_Name.Print(); }
private:
	String m_Name;
};

int main(int argc, char **argv)
{
	// we provide a temporary -- r-value 
	Entity entity(String("MEMEME"));
	entity.PrintName();
	
	/*
	 * Here we get 
	 * Created 
	 * Copied
	 * MEMEMEM
	 * 
	 * We what to get rid of 'Copied'
	 * 
	 */ 
	
	return 0;
}
