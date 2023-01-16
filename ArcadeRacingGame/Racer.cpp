#include "Racer.h"
#include <iostream>

Racer::Racer(Track& t, sf::Vector2f startPosition) : track(t)
{
	

	racerTexture.loadFromFile("assets/car.png"); //error check
	int pixStart = 0;
	for (int i = 0; i < 5; i++)
	{
		racerSprites.push_back(sf::Sprite(racerTexture, sf::IntRect(pixStart, 0, 32, 16)));
		pixStart += 32;
		racerSprites.at(i).scale(sf::Vector2f(2,2));
		racerSprites.at(i).setPosition(
			sf::Vector2f((startPosition.x) - racerSprites.at(i).getGlobalBounds().width / 2, (startPosition.y) - racerSprites.at(i).getGlobalBounds().height - 10));
	}

}

void Racer::drawElement(sf::RenderTarget& w)
{
	w.draw(racerSprites.at(2));//can go out of range
}

void Racer::update(const float& dt)
{
	
	racerSprites.at(2).setPosition(
		sf::Vector2f((GameGlobals::GAME_W / 2) - racerSprites.at(2).getGlobalBounds().width / 2,
			(GameGlobals::GAME_H)-racerSprites.at(2).getGlobalBounds().height - 10));

}

float Racer::distanceToTrackEdge()
{
	return std::abs(track.lines.at(track.lines.size() - 1).middlePt * GameGlobals::GAME_W - GameGlobals::GAME_W / 2);
}

