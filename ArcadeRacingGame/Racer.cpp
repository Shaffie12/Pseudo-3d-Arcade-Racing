#include "Racer.h"
#include <iostream>

Racer::Racer(sf::Vector2f startPosition)
{
	

	playerTex.loadFromFile("assets/car.png"); //error check
	int pixStart = 0;
	for (int i = 0; i < 5; i++)
	{
		playerSprites.push_back(sf::Sprite(playerTex, sf::IntRect(pixStart, 0, 32, 16)));
		pixStart += 32;
		playerSprites.at(i).scale(sf::Vector2f(2,2));
		playerSprites.at(i).setPosition(
			sf::Vector2f((startPosition.x) - playerSprites.at(i).getGlobalBounds().width / 2, (startPosition.y) - playerSprites.at(i).getGlobalBounds().height - 10));
	}

}

void Racer::drawElement(sf::RenderTarget& w)
{

	
	
	playerSprites.at(2).setPosition(
		sf::Vector2f((GameGlobals::GAME_W/2) - playerSprites.at(2).getGlobalBounds().width / 2,
			(GameGlobals::GAME_H) - playerSprites.at(2).getGlobalBounds().height - 10));
	w.draw(playerSprites.at(2));//can go out of range
}

void Racer::update(float amount, bool add)
{
	
	

}

