#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>

/*
 * Attemt to optimize how vectors work in C++
 * 
 * Optimization -- know your environemnt
 * How things work and how to adapt.use it
 * 
 * To ptimize the vector -- 
 * know how it works 
 * when elements are added -- if the capacity is exceeded,
 * the new memory needs to be allocated and everyting from
 * the old array has to be moved into the new one and the 
 * old one has to be deleted.
 * Reallocation -- is slow. 
 * Avoiding copying will speed up
 * 
 * Know when copy happes
 * 
 * In order to see how many time the object is copied --
 * use the "copy constructor"
 * 
 */  

struct Vertex
{
	float x, y, z;
	
	// add a normal constuctor
	Vertex(float x, float y, float z)
		: x(x), y(y), z(z) {}
	
	// add a copy method
	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	
	{
		std::cout << "Copied!" << std::endl;
	}
	
};

// overload stream for printing the Vertex
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << " , " << vertex.y << " , " << vertex.z;
	return stream;
}


int main(int argc, char **argv)
{
	// construct it 
	std::vector<Vertex> vertices;
	vertices.push_back({1,2,3}); // implicit conversion with initialization
	vertices.push_back({4,5,6}); // implicit conversion with initialization
	
	/* here we see that the 3 copies have been made! */
	
	vertices.push_back({7,8,9});
	
	/* now it is 9! */
	
	
	
	return 0;
}
