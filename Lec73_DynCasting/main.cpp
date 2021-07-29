#include <iostream>

/*
 * Dynamic casting is a special, safe type of casting
 * This is C++ type casting 
 * It makes sure that a cast is a valid cast 
 * 
 * It is a tool. It is evaluated at runtime --> overhead
 * 
 * It us used for casting across inheritance hierechy
 * 
 * If we have Entity -- can we cast to a Player instance
 * 
 * If "entity" == enemy
 * Dynamic cast of "entity" to player -- not valid casting
 * 
 * 
 * 
 * 
 * 
 * 
 */ 

class Entity
{
public:
	Entity(){ }
	virtual void PrintName(){}
};

class Player : public Entity
{
public:
	Player(){ }
};

class Enemy : public Entity
{
public:	
	Enemy(){ }
};

int main(int argc, char **argv)
{
	
	// Player has 2 types
	Player* player = new Player();
	Entity* i_am_player = player; // implicit cast -- fails
	Player* i_am_enemy = new Enemy(); // did not work... 
	
	// dangerous raw cast -- may give a crash
	Player* p = (Player*)e1;
	
	// this reqire Entity to be polymorphic class 
	// -- add a virtual function
	// this cast should fail -- return NULL
	Player* p2 = dynamic_cast<Player*>(i_am_enemy);
	
	// this cast will pass -- successfull cast
	Player* p3 = dynamic_cast<Player*>(i_am_player);
	
	// How does it know? That 'Entity' is a player and not "enemy"
	// This is doe at runtime RTTI -- types store more 
	// information
	
	// This is equivalent to checking if 
	// if something is an instance of another class
	
	return 0;
}
