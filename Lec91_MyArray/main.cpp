#include <iostream>
#include <array>
//#include <memory>
#include <cstring> // for memset
/*
 * Creating data structures
 * Creating Array on the stack
 * 
 * 1. We must use templates as the 
 *    stack allocated arrays require 
 *    to know the size at complile time
 *    not after. No dynamic allocation 
 *    on the stack (ish).
 * -  This issue can be overcome by 
 *    using 'alloca' (see example
 * 
 * 2. We use templates in order to 
 *    allow for a compiler-time creation 
 *    of an array of a given size
 *    Template allows to set type and size
 *    usially 'size_t' is used in this case
 * 
 * 3. Main feautues missing -- iterators
 *    fill and swap
 * 
 */ 



template<typename T, size_t S>
class Array
{
public:
	// constexpr can be evaluated at compile time
	//  v - compile-time      v - not modify calss
	constexpr size_t Size() const { return S; }
	// here we avoid storing the size ! 

	/// [READ/WRITE] ///
	// return by reference --
	// - Avoid copying when passing 
	// - Allows to modify the array -- assing
	T& operator[](size_t idx) { return m_array[idx]; }
	
	/// [READ ONLY] ///
	// if we want the array to be constant 
	// we SHOULD not be able to modify it -- you cannot use reference
	// this will not allow to read it
	// then need a method taht returns a copy of array eleemnt
	const T& operator[](size_t idx) const { return m_array[idx]; }

	/// [GET DATA] ///
	T* Data() { return m_array; }
	const T* Data() const { return m_array; }

private:
	// create array
	T m_array[S];
};

int main(int argc, char **argv)
{
	
	/// FOR A STANDARD ARRAY ///
	// this is example of a std::array
	constexpr int size = 10; // constexpr that is known
	std::array<int,size> arr;
	// you can check size of such array
	std::cout << arr.size() << std::endl;
	// you can use an iterator
	for (int i : arr)
	{
		std::cout << "element " << i << std::endl;
	}
	// Strangly the 'out-of-boud error is not raised... //
	arr[11] = 1;
	std::cout << "SHOULD BE ERROR!" << arr[11] << std::endl;
	
	
	/// Using alloca to create space on stack
	int _size2 = 10; // runtime value 
	int* arr2;
    arr2 = (int*)alloca(_size2 * sizeof(int));
	// this may lead to errors 
	// no compile iptimization
	
	
	/// our array
	Array<int,10> our_arr;
	std::cout << our_arr.Size() << std::endl;
	// using static assert -- check code AT COMPILE TIME
	// only works with vars KNOWN AT COMPILE TIME
	static_assert(our_arr.Size() < 11, "Size is too large(that's what she said)");
	
	
	for (size_t i=0; i<our_arr.Size(); i++)
	{
		// use overloaded T& [] operator to print values
		our_arr[i] = i;
	}
	
	for (size_t i=0; i<our_arr.Size(); i++)
	{
		// use overloaded T [] operator to print values
		std::cout << our_arr[i] << std::endl; 
	}
	
	// using GetData to set everyting to 0
	memset(our_arr.Data(), 0, our_arr.Size() * sizeof(int));
	// as the stack allocated array is contious in memry
	memset(&our_arr[0], 0, our_arr.Size() * sizeof(int));
	return 0;
}
