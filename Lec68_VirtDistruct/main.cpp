#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple
#include <array>
#include <algorithm> // for findif
#include <thread>
#include <chrono>
#include <typeinfo>

/*
 * Combo of virtual functions 
 * and 
 * In polymoriphsm
 * 
 * Whenever a class is subscribed -- 
 * its destructor must be vertual
 * 
 * 
 * 
 * 
 * 
 * 
 */ 


class Base
{
public:
	
	Base() { std::cout << "Base constructed " << std::endl; } 
	virtual ~Base() { std::cout << "Base distructed " << std::endl; } 
};


class Derived : public Base
{
public:
	
	Derived() { std::cout << "Derived constructed " << std::endl; } 
	~Derived() { std::cout << "Derived distructed " << std::endl; } 
};


int main(int argc, char **argv)
{
	std::cout << " ------ BASE ------ " << std::endl;
	Base* base = new Base();
	delete base;
	
	std::cout << " ------ DERIVED ------ " << std::endl;
	Derived* derived = new Derived();
	delete derived;
	
	
	// here the 'derived' destructor is not called!
	std::cout << " ------ POLY ------ " << std::endl;
	Base* poly = new Derived();
	delete poly;
	
	// a vertual distruction is not 'overriden'
	// in a sublcass -- it is ADDED
	// they all have to be called
	// so the mmeory is not freed from the Destructor of 
	// derived
	
	// Solition -- make distruction of the base virtual!
	
	return 0;
}
