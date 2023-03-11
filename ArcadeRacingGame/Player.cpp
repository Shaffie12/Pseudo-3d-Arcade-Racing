#include "Player.h"

Player::Player(Track& t, sf::Vector2f startPosition):Racer(t, startPosition) {}

void Player::handleInput(sf::Event& e)
{
	switch (e.type)
	{
	case sf::Event::KeyPressed:
		if (e.key.code == sf::Keyboard::A)
		{
			if (activeIdx != 0)
				activeIdx--;
		}
		else if (e.key.code == sf::Keyboard::D)
		{
			if (activeIdx != 4)
				activeIdx++;
		}
		break;
	case sf::Event::KeyReleased:
		activeIdx = 2;
		break;		
	}

	activeSprite = &racerSprites.at(activeIdx);
	
}



