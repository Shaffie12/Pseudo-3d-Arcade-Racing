#include "NpcRacer.h"


NpcRacer::NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color) :Racer(t, startPos, color), speed(std::rand() % 50 + 30)
{
	loadSprites(startPos,color);
	screenY = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - 150;
}

void NpcRacer::update(const float& dt)
{

	screenY = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - 150;
	sf::Vector2f position = activeSprite->getPosition();

	if(screenY + 150 > GameGlobals::GAME_H/2)
		activeSprite->setPosition(sf::Vector2f(position.x, position.y - speed * dt));

	swapSprite();
}

const float NpcRacer::distanceFromCenter(int& screenYPos) const
{
	float screen_x = activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2;
	return screen_x - track.lines.at(screenYPos).middlePt * GameGlobals::GAME_W;
}

void NpcRacer::swapSprite()
{
	
	if (screenY >= 90)
		activeSprite = &racerSprites.at(0);
	else if (screenY <90 && screenY >= 60)
		activeSprite = &racerSprites.at(2);
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
}
