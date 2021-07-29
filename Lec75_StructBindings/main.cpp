#include <iostream>
#include <tuple>

/*
 * This is for C++ 17
 * Allows to deal with multiple return 
 * values in C++
 * Tuples, pairs
 * 
 * For this lecture -- set 
 * "enable C++17 features in compiler settings"
 * 
 * 
 * 
 */ 
 
std::tuple<std::string, int> CreatePerson()
{
	return {"seva", 28};
}



int main(int argc, char **argv)
{
	
	/* in previos versions of C++ */
	{
	auto person = CreatePerson();
	std::string& name = std::get<0>(person);
	int age = std::get<1>(person);
	}
	
	/* or using the tie */
	{ 
	std::string name;
	int age;
	std::tie(name, age) = CreatePerson();
	}
	
	/* now, using the structured binding */
	auto[name, age] = CreatePerson();
	// now they are in the scope!
	
	return 0;
}
