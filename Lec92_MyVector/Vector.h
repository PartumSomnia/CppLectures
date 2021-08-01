#pragma once

/*
 * We do not want to re-allocate memory every time 
 * a new element is pushed back
 * We want to re-allocate only when the capacity 
 * is exceeded.
 * This reduces the number of re-allocations.
 * 
 */ 


// basic version :: copy only 
template<typename T>
class VectorV1
{
public:
	VectorV1()
	{
		// allocate memory -- even for an empty vector 
		// we want to have at least 2 elements
		
		ReAlloc(2); // re-allocate the memory; 2 -- initial
	}
	
	void PushBack(const T& value)
	{
		// check if there is enough space
		if (m_Size >= m_Capacity)
			// if not -- re-allocate to a bigger space
			ReAlloc(m_Capacity + m_Capacity / 2);
			
		// copy the element
		m_Data[m_Size] = value;
		m_Size++;
	}
	
	// create a [] operator to access elements of the array
	// no check if out-of-bounds
	const T& operator[](size_t index) const { return m_Data[index]; }
	
	// non-const version for modification
	// no check if out-of-bound
	T& operator[](size_t index) { return m_Data[index]; }
	
	
	// get the current size of the vector
	size_t Size() const { return m_Size; }
	
private:
	void ReAlloc(size_t newCapacity)
	{
		// 1. allocate a new block memory
		// 2. Copy/move all existing elements -> new block
		// 3. delete
		
		T* newBlock = new T[newCapacity]; // raw heep pointer
		
		// check if we are downsizing (copy up to new size then)
		// but we actually do not use it in the end
		size_t size = m_Size; // WARNING! this raises a warning :) 
		if (newCapacity < m_Size)
			m_Size = newCapacity;
		
		// next we 'copy' the data from old block to new
		// we have to do it element by elemnt and 
		// not memcpy() as we need to trigger the constructors
		for (size_t i = 0; i < m_Size; i++)
			newBlock[i] = m_Data[i];
			
		// delete olb block
		delete[] m_Data;
		
		// re-allocate the blocks
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:
	T* m_Data = nullptr; 	// pointer to whatever the type is 
	size_t m_Size = 0; 		// how much elements is stored
	size_t m_Capacity = 0; 	// how much memory is allocated
};



/// Try to change the above code to include MOVE instead of COPY
template<typename T>
class VectorV2
{
public:
	VectorV2()
	{
		// allocate memory -- even for an empty vector 
		// we want to have at least 2 elements
		
		ReAlloc(2); // re-allocate the memory; 2 -- initial
	}
	
	~VectorV2()
	{
		// delete an entire block of memory and call the 
		// destructor of each of them
		
		Clear(); // solves the error with deleting freed memory
		///delete[] m_Data; // MAY CAUSE AN ERROR
		// replace it with this ,this will not call any distructors
		// we called them separately in Clear()
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}
	
	// this takes the 'permanent vars'
	void PushBack(const T& value)
	{
		// check if there is enough space
		if (m_Size >= m_Capacity)
			// if not -- re-allocate to a bigger space
			ReAlloc(m_Capacity + m_Capacity / 2);
			
		// copy the element
		m_Data[m_Size] = value;
		m_Size++;
	}
	
		// this takes r-value refernece (however it 'becomes' permanent inside
	void PushBack(T&& value)
	{
		// check if there is enough space
		if (m_Size >= m_Capacity)
			// if not -- re-allocate to a bigger space
			ReAlloc(m_Capacity + m_Capacity / 2);
			
		// copy the element
		m_Data[m_Size] = std::move(value); // use move the FORCE it to be r-value
		m_Size++;
	}
	
	
	// Using Variadic template to create and EmplaceBack func
	// return T&
	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
		
		// create an instace right in the memory of the 
		// vector and pass into it the arguments from variadic 
		// template using std::forward<>()
		// This will do 'move' and 'destroy'
		///m_Data[m_Size] = T(std::forward<Args>(args)...);
		
		// instead of constructing and moving 
		// we can construct it in place 
		// use the "placemnt new()"
		// give the place in memory and give the object to place there
		new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
		
		// don't forget to increment the size
		return m_Data[m_Size++];
	}
	
	// remove the object at the end
	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T(); // call the destructor on the removed element
		}
	}
	
	// clear an entire Vector
	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();
		m_Size = 0;
	}
	
	// create a [] operator to access elements of the array
	// no check if out-of-bounds
	const T& operator[](size_t index) const { return m_Data[index]; }
	
	// non-const version for modification
	// no check if out-of-bound
	T& operator[](size_t index) { return m_Data[index]; }
	
	
	// get the current size of the vector
	size_t Size() const { return m_Size; }
	
	
	
private:
	void ReAlloc(size_t newCapacity)
	{
		// 1. allocate a new block memory
		// 2. Copy/move all existing elements -> new block
		// 3. delete
		
		
		///T* newBlock = new T[newCapacity]; // raw heep pointer
		// here there is actually no need to call a constructor 
		// we just need MEMORY using the operator 'new' from
		// general namespace :: to get this space in bytes 
		// This returns the void* so we cast it into T*
		T* newBlock = (T*)::operator new(newCapacity * sizeof(T));
		
		
		// check if we are downsizing (copy up to new size then)
		// but we actually do not use it in the end
		//size_t size = m_Size; // WARNING! this raises a warning :) 
		if (newCapacity < m_Size)
			m_Size = newCapacity;
		
		// next we 'copy' the data from old block to new
		// we have to do it element by elemnt and 
		// not memcpy() as we need to trigger the constructors
		for (size_t i = 0; i < m_Size; i++)
			newBlock[i] = std::move(m_Data[i]); // attempt to move as r-vale
			// if there is no move constructor -- it will just copy it
		
		// before we delete the memory, we call destructors on objects
		// Cear();
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();
		
		//instead of calling this delete we use from general namespace
		::operator delete(m_Data, m_Capacity * sizeof(T));
		
		// delete olb block -- WARNING you may delete already freed memory
		///delete[] m_Data; // MAY CAUSE AN ERROR
		
		// re-allocate the blocks
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:
	T* m_Data = nullptr; 	// pointer to whatever the type is 
	size_t m_Size = 0; 		// how much elements is stored
	size_t m_Capacity = 0; 	// how much memory is allocated
};