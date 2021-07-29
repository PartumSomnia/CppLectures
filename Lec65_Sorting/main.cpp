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
 * You can write your own code / algorithm for sorting
 * There are also in-built methods
 * std::sort()
 * (over any iterator)
 * It can sort with Lambda functions 
 * Complexity N*logN
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 

int main(int argc, char **argv)
{
	// sort in ascenting order
	std::vector<int> values = {3, 5, 7, 1, 9, 8};
	std::sort(values.begin(), values.end());
	for (int val : values) 
		std::cout << val << std::endl;
	// simple and fast sroting of an object with iterator)
	
	
	// using the std::functional function to sort (Lambda)
	// descendiing order!
	std::vector<int> values2 = {3, 5, 7, 1, 9, 8};
	std::sort(values2.begin(), values2.end(), std::greater<int>());
	for (int val : values2) 
		std::cout << val << std::endl;
		
	// using lambda
	// The policy is that the lambda must take 2 values
	// and return a bool, whether the first is prefferred over the second
	// this is equivalent to the first option
	std::vector<int> values3 = {3, 5, 7, 1, 9, 8};
	std::sort(values3.begin(), values3.end(), [](int a, int b){return a < b;});
	for (int val : values3) 
		std::cout << val << std::endl;
	
	return 0;
}
