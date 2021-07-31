#include <iostream>
#include <memory>
/*
 * A way to track the HEEP memory allocation
 * by globally overwriting the 'new' operator
 * and delete
 * 
 * 
 * 
 * 
 */ 

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;
	
	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
	//std::cout << "Allocating " << size << " bytes\n";
	// acclocate memory and return pointer to it
	
	s_AllocationMetrics.TotalAllocated += size;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	//std::cout << "Freeing " << size <<" bytes\n";
	s_AllocationMetrics.TotalFreed += size;
	free(memory);
}

void PrintmemoryUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

// create allocation tracker


struct Object
{
	int x, y ,z; // will allocate 12 bytes (3 ints)
};


int main(int argc, char **argv)
{
	PrintmemoryUsage();
	// using a simple pointer
	Object* obj = new Object;
	PrintmemoryUsage();
	// using a unique 
	std::unique_ptr<Object> obj2 = std::make_unique<Object>();
	PrintmemoryUsage();
	
	return 0;
}
