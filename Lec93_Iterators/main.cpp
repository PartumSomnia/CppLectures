#include <iostream>
#include <vector>
#include <unordered_map>
/*
 * Iterators are a way to iterate 
 * over the collection of data
 * Iterating through collections
 * This works through the so-called 'iterator',
 * specifically the iterator on the beginning 
 * and the end of the collection.
 * .begin() .end() -> returns the iterator
 * The iterators are not that crucual for 
 * the ranged based, sorted lists.
 * But for something like an unordered map -- 
 * they are the only way to loop through the elements
 * Examples : tree, unordered_set
 * 
 */ 

int main(int argc, char **argv)
{
	// given a class with terator implemented
	std::vector<int> vals = {1, 2, 3, 4, 5};
	// a way to print it is to loop over the elements
	for (int i = 0; i < vals.size(); i++)
		std::cout << vals[i] << std::endl;
		
	// or using the implemented iterator
	for (int val : vals)
		std::cout << val << std::endl;
	
	// this is how it is under-the-hood
	for (std::vector<int>::iterator it = vals.begin(); 
	     it != vals.end(); it++)
	{
		// here the * is implemented operator
		std:: cout << *it << std::endl; 
	}
	
	
	/// creating a map and using iterator 
	using ScoreMap = std::unordered_map<std::string, int>;
	ScoreMap map;
	map["Freinds"] = 0;
	map["Girlfriends"] = 0;
	
	for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
	{
		auto& key = it->first;
		auto& value = it->second;
		std::cout << key << " = " << value << std::endl;
	}
	
	std::cout << std::endl;
	
	// using the range based iterator
	for (auto kv : map)
	{
		// kv is an std::pair
		auto& key = kv.first; // getting them by reference -- not value
		auto& value = kv.second;
		std::cout << key << " = " << value << std::endl;
	}
	
	/// from C++17 we can use structured bindings
	for (auto [key, value] : map)
		std::cout << key << " = " << value << std::endl;
	
	
	return 0;
}
