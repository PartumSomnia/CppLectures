#pragma once

template<typename Vector>
class VectorIterator
{
public:
	// forlliwing the standard 
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
public:
    // the basis of the class is the pointer to where 
	// we are in the Vector
	VectorIterator(PointerType ptr)
		: m_Ptr(ptr) {}
	
	// increment operator
	VectorIterator& operator++()
	{
		m_Ptr++; // incrementing the pointer by the correct size
		return *this; // rethrn the VectorIterator reference
	}
	
	// post-fix operator
	VectorIterator operator++(int)
	{
		// returns a "copy" of the vector iterator
		// here, object in-place is not supposed to be modifed
		VectorIterator iterator = *this; // make a copy of Iterator
		++(*this); 			// call the ++ operator defiled above
		return iterator; 	// return the created copy
	}
	
	// decrement operator
	VectorIterator& operator--()
	{
		m_Ptr--; // decrement the pointer by the correct size
		return *this; // rethrn the VectorIterator reference
	}
	
	// post-fix operator
	VectorIterator operator--(int)
	{
		// returns a "copy" of the vector iterator
		// here, object in-place is not supposed to be modifed
		VectorIterator iterator = *this; // make a copy of Iterator
		--(*this); 			// call the -- operator defiled above
		return iterator; 	// return the created copy
	}
	
	// index operator
	ReferenceType operator[](int index)
	{
		return *(m_Ptr + index); // or *(m_Ptr[index])
	}
	
	PointerType operator->()
	{
		return m_Ptr; // current position of the pointer
	}
	
	// de-reference operator
	ReferenceType operator*()
	{
		return *m_Ptr;
	}
	
	// copmarison operator
	bool operator==(const VectorIterator& other) const 
	{
		return m_Ptr == other.m_Ptr;
	}
	
	bool operator!=(const VectorIterator& other) const 
	{
		return !(*this == other);
	}
	
private:
	PointerType m_Ptr;
};

template<typename T>
class Vector
{
public:
	// follwoing the standard library approach
	// the value type of the vector is T
	using ValueType = T;
	// in order to be able to use " Vector<int>::Iterator it = xxx "
	using Iterator = VectorIterator<Vector<T>>;
public:
	Vector()
	{
		ReAlloc(2);
	}
	
	// destructor
	~Vector()
	{
		Clear(); 
		::operator delete(m_Data, m_Capacity * sizeof(T));
	}
	
	// add elements to the end, and resize
	void PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
			
		m_Data[m_Size] = value;
		m_Size++;
	}
	
	// add an r-value (without copy)
	void PushBack(T&& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
			
		m_Data[m_Size] = std::move(value); 
		m_Size++;
	}
	
	// create an object in the memory of the vector element
	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);
		
		new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
		
		// return the created object
		return m_Data[m_Size++]; 
	}
	
	// remove the object at the end
	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T(); 
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
	const T& operator[](size_t index) const { return m_Data[index]; }
	
	// non-const version for modification
	T& operator[](size_t index) { return m_Data[index]; }
	
	
	// get the current size of the vector
	size_t Size() const { return m_Size; }
	
	
	/// --------- implemneting iterators --------------------
	// Note that both reqyure to know the type in <> 
	// the class is templated. In order to access it 
	// we create the TypeName and pass it into the VectorIterator
	
	Iterator begin() // VectorIterator
	{
		// beginning of the datablock is m_Data
		return Iterator(m_Data); // 
	}
	
	Iterator end() // VectorIterator
	{
		// the block of memory just past the allocation
		return Iterator(m_Data + m_Size);
	}
	
private:
	// move the eleemnts to a new memory if previos is too small
	void ReAlloc(size_t newCapacity)
	{
		// 1. allocate a new block memory
		// 2. Copy/move all existing elements -> new block
		// 3. delete

		T* newBlock = (T*)::operator new(newCapacity * sizeof(T));
		
		if (newCapacity < m_Size)
			m_Size = newCapacity;
		
		// move objects
		for (size_t i = 0; i < m_Size; i++)
		{
			/// error -- if a string is not properly created -- 
			///newBlock[i] = std::move(m_Data[i]);  /// HERE ERROR WITH STRING!
			new(&newBlock[i]) T(std::move(m_Data[i])); // use constructor properly
		}
		// destroy old objects (and their heap-allocations)
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();
		
		// delete memory from old objects
		::operator delete(m_Data, m_Capacity * sizeof(T));
			
		// re-allocate the blocks
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:
	T* m_Data = nullptr; 	// pointer to whatever the type is 
	size_t m_Size = 0; 		// how much elements is stored
	size_t m_Capacity = 0; 	// how much memory is allocated
};