#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple


/*
 * Tuples
 * Multiple return values
 * How to return 2 types? You cannot return.
 * A function in C++ return one type (one variable)
 * 
 * This can be done via creating a 
 * struct {
 *    var1 ... var2...
 * }
 * 
 * Another way is via passing the paramters via reference 
 * We can write into them
 * void(int& a, int& b)
 * 
 * Or use " vector / array " and wrap them 
 * 
 * tuple -- a class that can contain X amoutn of vars
 * 
 */ 


struct Tuple
{
	double x;
	double y;
};

// a 'simple' way to return a tuple -- everyting will be on the stack memory
static Tuple Func()
{
	double x = 2.;
	double y = 3.;
	return {x, y}; // return constructor 
}


int main(int argc, char **argv)
{
	
	std::tuple<std::string, std::string> test = std::make_pair<std::string, std::string>("Hey","You!");
	
	auto test2 = std::make_pair<std::string, std::string>("Hey","You!"); // simpler :) 
	
	std::string hi = std::get<0>(test2); // to get the value from tuple
	
	// simple to return a tuple
	Tuple res = Func(); // simple to get it 
	std::cout << res.x << ", " << res.y << std::endl; // simple to get access to the variables
	
	//std::string x = test; // undefined
	
	//std::cout << test << std::endl; // undefined
	
	return 0;
}
