#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple
#include <array>
#include <algorithm> // for findif

/*
 * Lambdas -- anonymous functions
 * "a quick disposable function"
 * 
 * It is used for whenever there is a function
 * pointer -- you can use a Lambda
 * Usage of a Lambda -- whenever the pointer was 
 * required 
 * 
 * 
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
//std::coud << "val: {}" << std::endl;
// here the lambda function is passed as a pointer to the function
void ForEach(std::vector<int>& vals, void(*func)(int))
{
	for (int value : vals) func(value);
}

void ForEach2(std::vector<int>& vals, const std::function<void(int)>& func)
{
	for (int value : vals) func(value);
}

int main(int argc, char **argv)
{
	
	std::vector<int> values = {1,2,3,4,5};
	// here 
	// [](int value){std::cout << "val:" << value << std::endl;}
	// is a lambda function
	ForEach(values, [](int value){std::cout << "val:" << value << std::endl;});
	
	// getting its type 
	// start woth []
	// pass ' captures ' to pass variables that are outside the lambda
	// into the lambda wither by value [=] pr by reference [&]
	int a = 1;
	auto Lambda = [=](int value){std::cout << a << "val:" << value << std::endl;};
	// we use an updated function here
	ForEach2(values, Lambda);
	
	// if we want the Lambda to modify values passed by value -- add 'mutable
	// note that pasing by 'value' actually creates a copy, so it
	// does not really make sense
	auto Lambda2 = [=](int value) mutable {a = 10; std::cout << a << "val:" << value << std::endl;};

	
	// using lammba for iterator:
	// use it to find the iter of the value that is > 3 in the vector
	auto iter = std::find_if(values.begin(), values.end(), [](int value){return value > 3;});
	// first -- dereference the iterator!
	std::cout << *iter << std::endl;
	
	return 0;
}
