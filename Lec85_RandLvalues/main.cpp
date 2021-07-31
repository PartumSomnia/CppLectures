#include <iostream>

/*
 * l - value -- vars that have storage
 * r - vals -- temp
 * lvalref -- take only l-val 
 * rvalref -- take only r-vals
 * 
 * 
 */ 

int func() // returns temp. r-value
{
	return 10;
}


int& func2() // returns temp l-value reference!
{
	static int value = 10; // storage for value
	return value;
}

void func3(int val)
{
	
}

// write a finction that ONLY accepts a temp object 
// an r-value 
void func4(const int&& val)
{
	std::cout << val << std::endl;
}

int main(int argc, char **argv)
{
	
	// left side = right value
	// l-value = r-value (but this is not always the case)
	int i = 10; 
	
	// l-value = l-value
	int a = i;
	
	// l-value = (func returns a (temporary) r-value)
	int c = func();
	
	///func() = 2; // ERROR! You cannot assign an r-vale something!
	// expression must be an modifiabe r-value
	
	func2() = 4; // Here the rer
	
	// A function that takes a parameter can be called with 
	// either an l-value or an r-value
	func3(10); // r-value
	func3(i);   // l-value
	/// You cannot take an l-value reference from r-value 
	//  i.e., int& a = 10; is impossible! But const int& a = 10 is.
	/// You can only take an l-value reference from l-value
	// func3(10) -- error! if func3 takes int& val
	
	/// Const references are compatible with both r- and l- vales
	//  that is why most funcs in C++ take something like
	//  const int& value
	
	// here only the temp (an r-value) can be assed! 
	func4(4);
	
	// This allows to detect temp. values
	// this is used in move() semantics -- optimization
	
	return 0;
}
