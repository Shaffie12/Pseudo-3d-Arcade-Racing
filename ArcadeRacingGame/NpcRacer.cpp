#include "NpcRacer.h"


NpcRacer::NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color) :Racer(t, startPos, color), baseSpeed(std::rand() % 10 + 8)
{
	screenY = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - 150;
}

//scale the npc speed by how far up the screen it is, also add some speed if the player stops moving
void NpcRacer::update(const float& dt)
{
	screenY = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - 150;
	sf::Vector2f pos = activeSprite->getPosition();

	float currentSpeed = baseSpeed * Racing::Util::convertRange(screenY, 0, 149, 0, 1) + (baseSpeed *3) * (1-track.acceleration);

	if(screenY + 150 > GameGlobals::GAME_H/2)
		activeSprite->setPosition(sf::Vector2f(pos.x, pos.y - currentSpeed * dt));

	position();
	scale();
}

const float NpcRacer::distanceFromCenter() const
{
	float screen_x = activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2;
	return screen_x - track.lines.at(screenY).middlePt * GameGlobals::GAME_W;
}

void NpcRacer::swapSprite()
{
}

void NpcRacer::scale() 
{
	int y = screenY;
	float scale = Racing::Util::clamp(Racing::Util::roundToDP(Racing::Util::convertRange(sqrt(y), 0, sqrt(149), 0.1f, 2), 1),0.1,2);
	
	activeSprite->setScale(scale, scale);
}

void NpcRacer::position()
{
	if (screenY < 90)
	{
		int y = screenY - 10 > 0 ? screenY - 5 : screenY;
		float positionScale = Racing::Util::clamp(Racing::Util::convertRange(screenY, 0, 80, 0, 1),0,1);
		activeSprite->setPosition(sf::Vector2f(activeSprite->getPosition().x - distanceFromCenter() * (1-positionScale), activeSprite->getPosition().y));
	}
		
}
