#ifndef PLAYER_H_
#define PLAYER_H_
#include "Racer.h"

class Player : public Racer
{
	public:
		Player(sf::Vector2f startPosition);
		int testInt = 0;
		
};
#endif 
