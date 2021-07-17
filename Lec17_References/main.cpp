#include <iostream>

#define LOG(x) std::cout << x << std::endl;

/*
 * References are an extension of pointers 
 * allows the easier read 
 * A refernece -- is a reference of the existing variable.
 * Reference MUST reference already existing variable.
 * They are not typical variable.
 * 
 * 
 * If you are passing a var into a func, a new COPY of this var 
 * is created. If you want to modify it -- you need to pass it BY REFERENCE
 * 
 * Algorithm *:
 * Pass a REFERENCE              func(&var);
 * Function takes a POINTER      void func(int* var);
 * Inside, it is DE-REFERENCED   (*var)++;
 * 
 * Algorithm &:
 * Pass a VARIABLE               func(var);
 * Function takes REFERENCE      void func(int& var);
 * Insider, it podifies var      var++;
 * 
 * In the later case what is really passed is an alias to the variable
 * that is modified. 
 * In the first example, a pointer is created to the variable
 * nad used to 'find it' and modify it.
 * 
 * Two methods are EQUIVALENT but references are cleaner, when they can
 * be used. Poisters are more versitile
 * 
 * Reference cannot be changed to be reference to another variable.
 * It is TIGHT to a given variable
 *
 */ 
 
 // pass the memory adress of the variable that is to be modified
 // It has to take a POINTER
 void Increment_ptr(int* value) 
 {
	 (*value)++; // de-reference FIRST -- then increment the value
 }

void Increment_ref(int& value)
{
	value++;
}

int main(int argc, char **argv)
{
	
	/* --- EXAMPLE WITH THE POINTER -- */
	
	int a = 5; // create a var
	// This exists only in a source code. This is alias. Compiler will remove it
	int& ref = a; // ampersant is the part of the type! 
	
	// pass the MEMORY adress of the variable
	Increment_ptr(&a);
	
	LOG(a); // print
	
	
	/* --- EXAMPLE with the REFERENCE --- */
	// pass 
	Increment_ref(a); 
	
	LOG(a);
	
	
	/* --- example of how a pointer can be a reference to 2 vars --- */
	
	int b = 5;  // make a var
	int c = 6;  // make another var
	int* ref2 = &b; // create a pointer to a var 'b' (recall that it is simply a nother var)
    ref2 = &c; // re-assigne the pointer to a different var, 'c'
	
	
	
	return 0;
}
