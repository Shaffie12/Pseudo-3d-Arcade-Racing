#include "NpcRacer.h"


NpcRacer::NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color) :Racer(t, startPos, color), speed(std::rand() % 50 + 30)
{
	screenY = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - 150;
}

void NpcRacer::update(const float& dt)
{
	screenY = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - 150;
	sf::Vector2f position = activeSprite->getPosition();

	if(screenY + 150 > GameGlobals::GAME_H/2)
		activeSprite->setPosition(sf::Vector2f(position.x, position.y - speed * dt));
}

const float NpcRacer::distanceFromCenter(int& screenYPos) const
{
	float screen_x = activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2;
	return screen_x - track.lines.at(screenYPos).middlePt * GameGlobals::GAME_W;
}

void NpcRacer::swapSprite()
{
	float screen_y = activeSprite->getPosition().y;
	/*
	if (screen_y < sprite_limits[0])
		activeSpr = &sprites[3];
	if (screen_y > sprite_limits[0])
		activeSpr = &sprites[2];
	if (screen_y > sprite_limits[1])
		activeSpr = &sprites[1];
	if (screen_y > sprite_limits[2])
		activeSpr = &sprites[0];
		*/


	scale();
}


void NpcRacer::scale() {}