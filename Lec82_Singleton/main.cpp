#include <iostream>

/*
 * Singletone is a class of which 
 * there is only one instance
 * 
 * Commpnly used for data/methods that 
 * are the same for the whole progeam
 * e.g., random number generator
 * Class like a namespace.
 * 
 * Singleton in C++ is a way to organize a banch 
 * of global varaible / static function
 * 
 * Think of the parameters for a phyical code,
 * like a blast wave initial parameters
 * 
 * 1) No constructor -- Private 
 * 2) A way to acess --a public func that returns 
 *    its instance
 * 
 * 
 * 
 */ 

/* ------------ BASIC CLASS ------------ */

class Singleton
{
public:
	static Singleton& Get()
	{
		// heave easy access to the instance
		return s_Instance;
	}
	
	void Func() { }

	// deleting copy-constructor
	Singleton(const Singleton&) = delete;

private:
	Singleton() {  }
	
	// class instance is its varaible 
	static Singleton s_Instance;
};

//  somewhere define the ONLY instance of the class
Singleton Singleton::s_Instance;


/* ----------- RANDOM GEN CLASS --------- */

class Random
{
public:
	Random(const Random&) = delete;
	
	static Random& Get()
	{
		// the instance will be created 
		// at first call 
		// and then picked up 
		// from the static memory
		static Random instance;
		return instance;
		//return s_RandInstance;
	}
	
	float Float() { return m_RandomNumber; }
	
	static float Float2() { return Get().GenRandNumb(); }
	
private:
	Random() {}
	float m_RandomNumber = 0.5f;
	static Random s_RandInstance;
	
	// allows to have a non-static member
	// access to member data
	float GenRandNumb()
	{
		return 0.5f;
	}
	
};

// this can be moved into static Get() method
//Random Random::s_RandInstance;


/* --------------- */
// allows for the same functionality!!!
// but with less control over private/public
namespace Example
{
	static float s_rand = .5f;
	static float Float() { return s_rand; }
}

int main(int argc, char **argv)
{
	
	// example of access -- on the instance
	Singleton::Get().Func();
	// this however allows to a mistake like 
	//    Singleton instance = Singleton::Get();
	// where the instance is COPIED!
	// in order to avoid it -- delete copy constructor
	//    then copy is impossible
	
	// consider example of a Dummy class 
	// for rundom number generation
	// To access a generated rundom number 
	// use 
	float number = Random::Get().Float();
	// or 
	auto& random = Random::Get();
	float numer2 = random.Float();
	
	
	// a simpler way without using Get()
	float number3 = Random::Float2();
	
	return 0;
}
