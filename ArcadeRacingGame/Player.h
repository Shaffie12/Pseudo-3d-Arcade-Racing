#ifndef PLAYER_H_
#define PLAYER_H_
#include "Racer.h"

class Player : public Racer
{
	public:
		Player(Track& t, sf::Vector2f startPosition);
		void handleInput();
		void update(const float& dt) override;

private:
	sf::Clock clock;
	bool turned = false;
	int activeIdx = 2;
		
		
};
#endif 
