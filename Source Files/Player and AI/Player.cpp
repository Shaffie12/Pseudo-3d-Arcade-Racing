#include "Player.h"

Player::Player(Track& t, sf::Vector2f startPosition):Racer(t, startPosition) {}

void Player::handleInput(sf::Event& e)
{
	if (GameGlobals::useController && GameGlobals::controller_connected)
	{
		float stick_x = Racing::Util::convertRange(Racing::Util::clamp(sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::X), -80.0f, 80.0f), -80.0f, 80.0f, -1.0f, 1.0f);

		if (stick_x < -0.2f)
		{
			if (activeIdx != 0)
				activeIdx--;
		}
		else if (stick_x > 0.2f)
		{
			if (activeIdx != 4)
				activeIdx++;
		}
		else
		{
			activeIdx = 2;
		}
	}		
	else
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
	}
	

	activeSprite = &racerSprites.at(activeIdx);
	
}



