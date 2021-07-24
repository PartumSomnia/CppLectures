#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>

/*
 * Consider C++ standard Template libraries
 * Underlying datatype of the conainer user-set
 * 
 * std::vector() 
 * is not actually a vector -- this is dynamic array
 * It is a set, but in instead of raw arrays it can 
 * resize
 * The size can be given, but it can be changed
 * Size can grow and shrink
 * 
 * Usually stuff in a standard library is not 
 * well optimized for performance. It can be 
 * sped up using custom data containers 
 * (think -- athena arrays)
 * 
 * Whenever the array exceeds its basic size,
 * a new array is created and stuff is moved around
 * 
 * 
 * 
 */ 

struct Vertex
{
	float x, y, z;
};

// overload stream for printing the Vertex
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << " , " << vertex.y << " , " << vertex.z;
	return stream;
}


int main(int argc, char **argv)
{
	std::vector<Vertex> vertices;
	/*
	 * Question: what to store: objects or pointers to objects?
	 * Essencially: what to store? Pointers to heep allocated 
	 * classes in vector or stack allocated structs?  
	 * The answer: -- it depends) 
	 * Primary: -- it is more optimal to store objects
	 * then pointers.
	 * Inline storage -- xyz,xyz, -- optimal for consequative 
	 * operations.
	 * 
	 * 
	 */ 
	vertices.push_back({1,2,3}); // implicit conversion with initialization
	vertices.push_back({4,5,6}); // implicit conversion with initialization
	
	for (int i = 0; i < vertices.size(); i++)
	{
		// here we a) using overload from vector class for [] operator
		//         b) using our own overload for << of a Vertices class
		std::cout << vertices[i] << std::endl;
	}
	
	// a more elegant way to print vector is 
	// add & to pass is as a reference -- avoid copying
	for (const Vertex& v : vertices)
	{
		std::cout << v << std::endl;

	}
	
	// remove one element
	vertices.erase(vertices.begin() + 1);
	
	// delete the entire thing
	vertices.clear(); // sets the array size to 0
	
	
	
	return 0;
}
