#include <iostream>
#include <string>

/*
 * mutable has 2 uses :: one with const
 * second with lambdas
 * 
 * Lambda is a small through-away function
 * 
 * 
 */ 

class Entity 
{
private:
	int m_X, m_Y;
	int* mp_X, *mp_Y; // pointers for each
	mutable int cheat = 1; // can be chaged in const methods 
public:
	// here const stands m_x = 2 will ERROR! 
	// method does not modify vars in the class
	int GetX() const  
	{
		cheat++; // mutable can be changed in static method!
		return m_X;
	}
	 
	// return a pointer that cannot be modified
	// the content of this pointer cannot be modified
	// and the method cannot modify stuff of the class
	const int* const GetX2() const
	{
		return &m_X;
	}
	 
	void Setx(int x)
	{
		m_X = x;
	}
};

void PrintGet(const Entity& obj)
{
	std::cout << obj.GetX() << std::endl;
}

int main(int argc, char **argv)
{
	Entity obj = Entity();
	obj.Setx(10);
	PrintGet(obj);

	// lambda func
	int x = 10;
	auto f = [&]() // passing everyting by reference '='
	{
		x++;
		std::cout << x << std::endl;
	};
	
	// in order to change variables passed in labmda by 
	// vaue '=' you have to use mutable
	int y = 5;
	auto fm = [=]() mutable
	{
		y++;
		std::cout << y << std::endl;
	};
	std::cout << y << std::endl;
	// Here y is still 5! In lambda you passed A COPY
	
	return 0;
}
