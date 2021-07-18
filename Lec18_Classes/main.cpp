#include <iostream>

/*
 * C++ allows for object orientated programming
 * Classes :: grouping data and functionality
 * 
 * Class is its own type
 * 
 * Variables made of class types are called objects
 * New object variable is called instance
 * 
 * Classes -- synthatic shuger to make code look nicer
 * 
 */ 

#define LOG(x) std::cout << x << std::endl;


class Player
{
public: // only then the vars can be accessed from outside

	int x, y; // vars, visible for any method of the class
    int speed;
	
	// You do not use self. here as in Python. Class variables are 
	// accessable by defauld -- They are known within the scope of the class
	void Move2(int xa, int ya)
	{
		x += speed * xa;
		y += speed * ya;
	}

};

// separate function that modifies the instance properties
void Move(Player& player, int xa, int ya)
{
	player.x += player.speed * xa;
	player.y += player.speed * ya;
}

int main(int argc, char **argv)
{
	
	Player player;
	player.x = 2;
	Move(player, 1, -1); // use external function
	player.Move2(1, -1); // use object method
	
	return 0;
}
