#include "Racer.h"

Racer::Racer(sf::Vector2f startPosition) : dir(f)
{
	dir = f; //want to move these to a player class

	playerTex.loadFromFile("assets/car.png");
	int pixStart = 0;
	for (int i = 0; i < 5; i++)
	{
		playerSprites.push_back(sf::Sprite(playerTex, sf::IntRect(pixStart, 0, 32, 16)));
		pixStart += 32;
		playerSprites.at(i).scale(sf::Vector2f(3, 3));
		playerSprites.at(i).setPosition(sf::Vector2f((startPosition.x) - playerSprites.at(i).getGlobalBounds().width / 2, (startPosition.y) - playerSprites.at(i).getGlobalBounds().height - 10));
	}

}

void Racer::drawElement(sf::RenderWindow& w)
{
	w.draw(playerSprites.at(2));//can go out of range
}

void Racer::changeDir(direction d) { dir = d; }