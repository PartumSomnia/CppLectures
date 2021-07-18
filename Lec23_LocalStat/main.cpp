#include <iostream>

/*
 * Static in a local scope -- 3rd meaning
 * lifetime and the scope of the variable
 * lifetime -- how long
 * scope -- where it is accesable
 * static local variable -- will live for the whole program lifetime
 * 
 * For a static in a class and function scopes the lifetime 
 * is the same
 * 
 * The use of this -- for specific cases
 * Similar to SIngleton classes                                                                        
 * 
 * Static inside func() and class 
 * can replace the __init__ and definitions, 
 * make code cleaner.
 * 
 * 
 */ 

/* Example of having ONE instance of a class for all code */
class Singleton
{
private:
	static Singleton* s_Instance;
public:
	// 
	static Singleton& Get() {return *s_Instance; }
	
	void Hello() {}
};

Singleton* Singleton::s_Instance = nullptr;

/* same example but with static */
// to achieve the same behaviour
class SingletonStat
{
public:
	// 
	static SingletonStat& Get() 
	{
		// once created, exists alwaus!
		static SingletonStat instance;  
		return instance;
	}
	
	void Hello() {} 
};



// int i = 0; // Equivalent to having static int; inside!
void Func()
{
	static int i = 0; // intiialized onced!
	i++;
	std::cout << i << std::endl;
}

int main(int argc, char **argv)
{
	Func();
	Func();
	Func();
	// i = 5; // This does change 
	Func();
	// Note that i++ modifes the 'i' that was initilized ONCED
	// Onced initilized 'i' existis FOREVER 
	
	Singleton::Get().Hello();
	
	return 0;
}
