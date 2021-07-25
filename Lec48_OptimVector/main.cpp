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
	// construct in the stack in MAIN 
	std::vector<Vertex> vertices;
	// move the vertex -> memory that vector has allocated! (1.Copy)
	vertices.push_back({1,2,3}); // implicit conversion with initialization
	vertices.push_back({4,5,6}); // implicit conversion with initialization
	vertices.push_back({7,8,9});
	/* here we see that the 3 copies have been made! */
	
	vertices.push_back({10,11,12});
	
	/* now it is 9! copies 
	 * But why? 
	 * 
	 * So. When we construct Vector in {1,2,3} -- it is allocated
	 * in stack in main.
	 * Next, it is "placed" into vertex. But this is actaully 
	 * copying! 
	 * The optimiation :: create the vector ALREAY in the memory
	 * that vector has allocated for you
	 * 
	 * Each time we push +1 Vector, the Vector is resized!
	 * If it is known how many objects are there initially,
	 * we can initially create verteces[3]
	 * 
	 * 
	 */
	 
	std::cout << "optimized" << std::endl;
	 
	// optimized code:
	std::vector<Vertex> vertices2; //(3) will CONSTRUCT 3 objects, we do not want that
	vertices2.reserve(3); // difference from resize! // enough memory
	vertices2.emplace_back(1,2,3); // implicit conversion with initialization
	vertices2.emplace_back(4,5,6); // implicit conversion with initialization
	vertices2.emplace_back(7,8,9);
	
	// with 'push_back' here we got only 3 copies -- for each obj "copied" into Vertex
	
	// emplace_back -- 'moves' not copies the obj there
	// emplace_back() takes the parameter list for the constructor
	
	// now NO COPIES are made
	
	return 0;
}
