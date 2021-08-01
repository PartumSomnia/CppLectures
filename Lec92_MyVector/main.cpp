#include <iostream>
#include <string>
#include <cstring>
#include "Vector.h"

/*
 * In this example the custom 'vector' 
 * class is created. It allows to 
 * - pushBack elements
 * - emplaceBack class istances (instead of copying/moving)
 * - resizing
 * 
 * The design begins with designing an API
 * -- what the class should be able to do:
 * e.g., 
 * 		- Create with no size
 * 		- Access an element
 * 		- PushBack
 * 		- EmpalceBack
 * 		- Resize when a size is exceeded
 * 		- ...
 * 
 * Note: for a simple object with simple data, e.g. floats
 * copy is not a problem. 
 * The optimization is required when big, heap-allocated 
 * objects are copied in the re-allocation within the vector class
 * this can be optimized -- create overload for r-value
 * 
 * Implementing the EmplaceBack() 
 * instead of creating a temp. objet and then passing it and moving 
 * into the Vector2() -- create the object right there, 
 * in the vector memory
 * This is achieved using "vaiatic template<> "
 * 
 * Final note on the DELETE flaw
 * with allocation and de-allocation memory
 * The issue is that in the pop-pack and clear we are 
 * manually calling the destructors -- i.e. we are freeing mmeory
 * If then delete[] tries to clear the same memory -- ERROR!
 * 
 * 
 * 
 * WARNING 
 * This works only with rustc compiler.
 * Have no idea why...
 * 
 * 
 * 
 */ 


///---------------------------------------------------------------------///

template<typename T>
void PrintVector(const VectorV1<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;
	std::cout << " ---------------- " << std::endl;
}

///---------------------------------------------------------------------///


// using the VectorV1 class with only copying 
void TestVectorV1()
{
	VectorV1<std::string> vector;
	vector.PushBack(std::string("Hi! "));
	vector.PushBack("My ");
	vector.PushBack("name ");
	vector.PushBack("is ");
	vector.PushBack("Seva! ");
	vector.PushBack("I ");
	vector.PushBack("am ");
	vector.PushBack("lonely ");
	vector.PushBack(":(");
	PrintVector(vector);
	
}

///---------------------------------------------------------------------///

// custom class to track what is going on with the element 
// of the Vector class -- copies, moves, destructions
struct Vector3
{
	float x=0.0f, y=0.0f, z=0.0f;
	int* m_MemBlock = nullptr;
	// three constructors
	
	Vector3() 
	{
		m_MemBlock = new int[5]; 
	}
	
	Vector3(float scalar) 
		: x(scalar), y(scalar), z(scalar) 
	{ 
		// allocate heap memory to make the Vector3 complex :) 
		m_MemBlock = new int[5]; 
	}
	
	Vector3(float x, float y, float z) 
		: x(x), y(y), z(z) 
	{
		// allocate heap memory to make the Vector3 complex :) 
		m_MemBlock = new int[5]; 
	}
	
	// copy constructor (to track copies
	Vector3(const Vector3& other) // = delete; // to remove it!
		: x(other.x), y(other.y), z(other.z)
	{
		// allocate heap memory to make the Vector3 complex :) 
		m_MemBlock = other.m_MemBlock; 
		
		std::cout << "Copied!" << std::endl;
	}
	
	// move constructor -- to track moves (i like to move it move it:) 
	Vector3(Vector3&& other)
		: x(other.x), y(other.y), z(other.z)
 	{
		m_MemBlock = other.m_MemBlock;
		other.m_MemBlock = nullptr;
		
		std::cout << "Move!" << std::endl;
	}
	
	// add a destructor (to track destructions)
	~Vector3()
	{
		std::cout << "Destroyed!" << std::endl;
		delete[] m_MemBlock;
	}
	
	// provide assigment operators
	Vector3& operator=(const Vector3& other) //= delete; // to remove it!
	{
		
		m_MemBlock = other.m_MemBlock;
		//other.m_MemBlock = nullptr;
		
		std::cout << "Copy\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	
	Vector3& operator=(Vector3&& other)
	{
		
		m_MemBlock = other.m_MemBlock;
		other.m_MemBlock = nullptr;
		
		std::cout << "Move\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};




// a templated method to print it 
template<>
void PrintVector(const VectorV1<Vector3>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
	std::cout << " ---------------- " << std::endl;
}

void PrintVector2(const VectorV2<Vector3>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
	std::cout << " ---------------- " << std::endl;
}

///---------------------------------------------------------------------///


// using the VectorV1 class with only copying 
void TestVectorV1WithVector3()
{
//	std::cout << "using copy constructor" << std::endl;
//	VectorV1<Vector3> vector;
//	vector.PushBack(Vector3(1.f, 2.f, 3.f));
//	vector.PushBack(Vector3(10.0f));
//	vector.PushBack(Vector3());
//	PrintVector(vector);
//	
//	std::cout << "using move constructor for r-values" << std::endl;
//	VectorV2<Vector3> vector2;
//	vector2.PushBack(Vector3(1.f, 2.f, 3.f)); //temporary
//	vector2.PushBack(Vector3(10.0f));
//	vector2.PushBack(Vector3());
//	PrintVector2(vector2);
//	// here the copy is still called but only in 'relocation'
//	// after -- everything is moved -- nothing copied
	
	std::cout << "using EmplaceBack function" << std::endl;
	VectorV2<Vector3> vector3;
	vector3.EmplaceBack(1.f, 2.f, 3.f); //temporary
	vector3.EmplaceBack(3.f, 4.f, 5.f); //temporary
	vector3.EmplaceBack(6.f, 7.f, 8.f); //temporary
	vector3.EmplaceBack(9.f, 10.f, 11.f); //temporary
	vector3.EmplaceBack(20.0f);
	vector3.PopBack();
	vector3.EmplaceBack(30.0f);
	vector3.EmplaceBack(40.0f);
	vector3.PopBack();
	vector3.EmplaceBack();
	PrintVector2(vector3);
	
	vector3.Clear();
	
	vector3.EmplaceBack(30.0f);
	vector3.EmplaceBack(40.0f);
	
	PrintVector2(vector3);
}





int main(int argc, char **argv)
{
	// Try the cector class on strings
	TestVectorV1();
	
	// try the vector class on objects 
	TestVectorV1WithVector3();
	
	
	std::cout << "--Done--" << std::endl;
	return 0;
}
