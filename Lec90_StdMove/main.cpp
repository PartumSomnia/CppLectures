#include <iostream>
#include <string>
#include <cstring>
/*
 * The classes are from the Lec89_Move 
 * Here we consider how to use the std::move()
 * 
 * A regular assingment operator is similar to move() constructor
 * String(String&& other) 
 * 
 * WARNING! 
 * I get an error at runtime for delte[] in move operator
 * I do not understand why
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
	
	// write a move assignemnt operator
	String& operator=(String&& other) noexcept// not supposed to be throwing exceptions
	{	
		printf("Reassign!\n");
		// make sure that the 'other' is not 'this' 
		// otherwisse you copy itself
		if(this != &other)
		{
			// we need to overwrite the current object
			// to avoid memory leak
			delete[] m_Data;
			
			m_Size = other.m_Size;
			m_Data = other.m_Data; // re-assigning a pointer
			//memcpy(m_Data, other.m_Data, m_Size); // no memory 
			
			// get rid of the previous instance
			other.m_Size = 0;
			other.m_Data = nullptr; // so that Descturctor does not 
			// destroy our "relocated" object
		}
		return *this;
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
	
	/// constructor that takes a temporary (for r-value)
	// Entity(String&& name)
	//	: m_Name((String&&)name) {} // here the copy still happns! -> cast it into temporary
	// next we apply the std::move to the pile!
	Entity(String&& name)
		: m_Name(std::move(name)) {} // here the copy still happns! -> cast it into temporary
	
	void PrintName() { m_Name.Print(); }
private:
	String m_Name;
};

int main(int argc, char **argv)
{
	
#if 0

	// we provide a temporary -- r-value 
	Entity entity(String("MEMEME"));
	entity.PrintName();
	
	/* --- consider as impler example of the move --- */
	
	String string = "Hi";
	String dest = string; // this is copy! Note move into a new varaible
	// in order to 'move' the temporaty (r-value) object is required
	String dest2 = (String&&)string; // Equivalent to String dest((String&&)string);
	// with implicit constructor
	// This will however will not work for all types
	// use std::move()
	String dest3(std::move(string)); // here we 'move' string -> distratanation
	String dest4 = std::move(string); // THE SAME!
	// This is a brand new object -- using the move constructor.
	
	// assignemnt operator ' = ' only is called when a var is 'assinged' to existing var
	// dest = std::move(string); // here the 'assingment is called'
#endif
	printf("Checking the assingment operator\n");
	
	
	String apple = "Apple";
	String dest_for_apple; // creating empty string
	
	std::cout << "Apple ";
	apple.Print();
	std::cout << "Dest ";
	dest_for_apple.Print();
	
	dest_for_apple = std::move(apple);
	
	std::cout << "Apple ";
	apple.Print(); // should be empty
	std::cout << "Dest ";
	dest_for_apple.Print();
	
	std::cout << " end " << std::endl; 
	
	return 0;
}
