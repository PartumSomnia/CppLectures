#include <iostream>
#include <memory>
#include <string>
#include <cstring>
/*
 * coptying an object from one 
 * place to another. 
 * It takes time. Overhead.
 * 
 * Comment 
 * StringCl(const StringCl& other)
 * to see the error due to shallow copy!
 * 
 * ALWAYS PASS THE OBJECT BY CONST REFERENCE!
 * 
 */ 

struct Vector2
{
	int x, y;
};


class StringCl
{
private:
	
	char* m_Buffer; // pointer
	unsigned int m_len;
	
public:
	StringCl(const char* input)
	{
		m_len = strlen(input); // get number of chars
		m_Buffer = new char[m_len + 1]; // allocate memory (heep)
		memcpy(m_Buffer, input, m_len); // copy into that memry
		m_Buffer[m_len] = 0; // manually adding NULL termination
	}
	
	// create an overload for the operator
	friend std::ostream& operator<<(std::ostream& stream, const StringCl& string);
	
	// overaload for operator []
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}
	
	// define a Copy constructor -- This is a default construction!
	// It is inadequte -- WE DO NOT WANT TO COPY THE POINTER
//	StringCl(const StringCl& other) 
//		: m_Buffer(other.m_Buffer), m_len(other.m_len)
//	{
//		
//	}
	StringCl(const StringCl& other)
	{
		std::cout << "copied..." << std::endl;
		m_len = other.m_len; // this is just an int. Can be copied 'shallow'
		m_Buffer = new char[m_len+1]; // account for null termination
		memcpy(m_Buffer, other.m_Buffer, m_len+1);// account for null termination
	}
	
	// without deleting, the m_Buffer will outlive the class!
	~StringCl()
	{
		delete[] m_Buffer; // prvent memory leaks
	}
};

/*
 * Friend allows to access the private memember of the class
 * 
 */ 

// define 
std::ostream& operator<<(std::ostream& stream, const StringCl& string)
{
	stream << string.m_Buffer;
	return stream;
}

// here you can pass the object, but that WILL COPY IT!
// Passind by reference lifts this issue!
// mark it as a const -- it is not meant to modify it!
void PrintStr(const StringCl& cl)
{
	// pass
}


int main(int argc, char **argv)
{
	// copyting integers
	int a = 2;
	int b = a;
	// here b is a COPY of a
	
	// copyting objects 
	Vector2 v_a = { 2, 3 };
	Vector2 v_b = v_a;
	// here a new object is created and assigned a COPY of a
	
	// However, if we consider 'heap' allocation
	Vector2* p_va = new Vector2();
	Vector2* p_vb = p_va;
	// here the POINTER is copied -- not the memory context
	// and this:
	p_vb->x = 2;
	// affects BOTH p_va and p_vb
	std::cout << p_va->x << " , " << p_va->y << std::endl;
	std::cout << p_vb->x << " , " << p_vb->y << std::endl;
	// See! Both have changed!
	
	
	/* --- using the StrincCL --- */
	
	StringCl string = "Seva";
	StringCl string2 = string;
	
	std::cout << string << std::endl;
	std::cout << string2 << std::endl; // This will give an ERROR!
	// free(): double free detected in tcache 2
	
	/*
	 * The origin of this error is quite tricky.
	 * When you create a copy of the class in 
	 * > StringCl string2 = string;
	 * you perform a "shallow copy", meaning that 
	 * all the varaibles of the class get copied 
	 * but the pointers are pointed at the same block
	 * of memory, -- m_Buffer is thus ONE for both 
	 * copies. 
	 * You delete it once (when calling destructor,
	 * but you cannot delete it again! in the second
	 * object desctructor)
	 * 
	 */ 

	
	// next, consider cnahing one of the strings
	string[2] = 'a'; // this changes BOTH of the objects
	std::cout << string << std::endl;
	std::cout << string2 << std::endl; // This will give an ERROR!
	
	/*
	 * Se Essencially we have to string objects,
	 * with pointers in them, pointing on the exact same memory adress
	 * Shallow copy copies only the object, not to where pointers 
	 * in it point to.
	 * 
	 * we want to COPY this block of memory -- with a different pointer
	 * 
	 * This requires DEEP copy!
	 * 
	 * We write a copy constructor!
	 * 
	 * Default C++ copy constructior has a signature 
	 * > Class(const Class& other)
	 * It is essencially memcopy
	 * 
	 */ 
	 
	// Perform deepcopy will solve the issure
	
	PrintStr(string);
	PrintStr(string2);
	
	// to avoid copying -- use reference!
	
	return 0;
}
