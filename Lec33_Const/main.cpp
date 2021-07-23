#include <iostream>
#include <cstring> // for strlen()
#include <stdlib.h>

/*
 * Connst -- it is a promist that can be broken
 * It is for ease of coding, nothing more.
 * 
 * 
 * 
 */ 
 
 
 class Entity 
 {
private:
	 int m_X, m_Y;
	 int* mp_X, *mp_Y; // pointers for each
	 mutable int cheat = 1;
public:
	 // here const stands m_x = 2 will ERROR! 
	 // method does not modify vars in the class
	 int GetX() const  
	 {
		 cheat++; // mutable can be changed in static method!
		 return m_X;
	 }
	 
	 // return a pointer that cannot be modified
	 // the content of this pointer cannot be modified
	 // and the method cannot modify stuff of the class
	 const int* const GetX2() const
	 {
		 return &m_X;
	 }
	 
	 void Setx(int x)
	 {
		 m_X = x;
	 }
 };


// passing the const reference -- only work with
// const methods of the class
void PrintEntX(const Entity& entity)
{
	// Since the const reference is passed -- 
	// the only way to assure that GetX() does not 
	// modify the object, is for GetX() to be CONST! 
	std::cout << entity.GetX() << std::endl;
}

int main(int argc, char **argv)
{
	
	// this integer cannot be modified
	const int a = 5;
	// For example -- a=6 would give an error
	
	// create a pinter for AN integer on the heep
	int* b = new int;
	// de-reference the pointer and assign the value 2
	*b = 2;
	// print the dereferenced pointer -- value
	std::cout << *b << std::endl; 
	
	// the pointer can also be re-assigned 
	int c = 4;
	// reassigne
	b = (int*)&c;
	std::cout << *b << std::endl; 
	
	// however, if the pointer was a const
	// the content of the pointer cannot be changed
	const int* d = new int;
	// *d = 5; -- ERROR you cannot change the conent of the pointer
	// BUT you can de-reference for READ
	std::cout << *d << std::endl;
	
	
	
	// this creats the pointer to a FIXED CONTENT; *ca = 2 ERROR; YOU CAN REASSIGN
	int const* ca = new int;
	const int _b = 10;
	ca = (int*)&_b;
	
	// Contents can be changed BUT *cb = 2; OK; NO REASSIGNEING
	int* const cb = new int; 
	*cb = 10;
	
	// Note that 
	// const int* a = int const* a !!! But not equal to int* const 
	// key is const before * 
	// if you want to reassined you put it before const 
	
	// here NEITHER content nor pointer itself can be changed
	const int* const cca = new int;
	
	
	return 0;
}
