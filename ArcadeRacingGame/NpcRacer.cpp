#include "NpcRacer.h"


NpcRacer::NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color) :Racer(t, startPos, color), baseSpeed(std::rand() % 10 + 8)
{
	loadSprites(startPos,color);
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

	swapSprite();
	position();
}

const float NpcRacer::distanceFromCenter() const
{
	float screen_x = activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2;
	return screen_x - track.lines.at(screenY).middlePt * GameGlobals::GAME_W;
}

void NpcRacer::swapSprite()
{
	sf::Vector2f position = activeSprite->getPosition();
	if (screenY < 70)
		activeSprite = &racerSprites.at(2);
	if (screenY < 30)
		activeSprite = &racerSprites.at(4);
	if (screenY < 8)
		activeSprite = &racerSprites.at(5);
	if (screenY < 1)
		activeSprite = &racerSprites.at(6);
	if(screenY ==0)
		activeSprite->setColor(sf::Color::Transparent);

	activeSprite->setPosition(position);
		
	
}

void NpcRacer::loadSprites(sf::Vector2f startPosition, sf::Color color)
{
	racerSprites.clear();
	int ix = 0;
	int iy = 0;
	int yIdx = 0;
	int acrossIdx = 0;
	int downIdx = 0;

	for (int i = 0; i < 7; i++)
	{
		sf::Sprite s(ImageManager::GetInstance()->enemyCar, sf::IntRect(ix, spritesY[yIdx], spritesAcross[acrossIdx], spritesDown[downIdx]));
		racerSprites.push_back(s);
		racerSprites.at(i).setScale(2, 2);
		racerSprites.at(i).setPosition(
			sf::Vector2f((startPosition.x) - racerSprites.at(i).getGlobalBounds().width / 2, (startPosition.y) - racerSprites.at(i).getGlobalBounds().height - 10));
		racerSprites.at(i).setColor(color);

		ix += 1 + spritesX[i];
		iy = spritesY[yIdx];

		if (i != 6)
		{
			yIdx++;
			acrossIdx++;
			downIdx++;
		}	

	}

	//reassign default
	activeSprite = &racerSprites.at(0);
}

void NpcRacer::scale() {}

void NpcRacer::position()
{
	if (screenY < 90)
	{
		int y = screenY - 5 > 0 ? screenY - 5 : screenY;
		float positionScale = Racing::Util::clamp(Racing::Util::convertRange(screenY, 0, 80, 0, 1),0,1);
		activeSprite->setPosition(sf::Vector2f(activeSprite->getPosition().x - distanceFromCenter() * (1-positionScale), activeSprite->getPosition().y));

	}
		
}
