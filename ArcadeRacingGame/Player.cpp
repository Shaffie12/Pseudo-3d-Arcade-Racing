#include "Player.h"

Player::Player(Track& t, sf::Vector2f startPosition):Racer(t, startPosition) {}

void Player::handleInput()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if(!turned)
		{ 
			turned = true;
			clock.restart();
			if (activeIdx != 0)
			{
				activeIdx--;
				activeSprite = &racerSprites.at(activeIdx);
			}
		}
	}
	

}

void Player::update(const float& dt)
{
	handleInput();
	Racer::update(dt);

}

