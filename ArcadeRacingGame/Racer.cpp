#include "Racer.h"
#include <iostream>

Racer::Racer(sf::Vector2f startPosition):playerCurvature(0)
{
	

	playerTex.loadFromFile("assets/car.png"); //error check
	int pixStart = 0;
	for (int i = 0; i < 5; i++)
	{
		playerSprites.push_back(sf::Sprite(playerTex, sf::IntRect(pixStart, 0, 32, 16)));
		pixStart += 32;
		playerSprites.at(i).scale(sf::Vector2f(3, 3));
		//playerSprites.at(i).setPosition(sf::Vector2f((startPosition.x) - playerSprites.at(i).getGlobalBounds().width / 2, (startPosition.y) - playerSprites.at(i).getGlobalBounds().height - 10));
	}

}

void Racer::drawElement(sf::RenderWindow& w)
{
	w.draw(playerSprites.at(2));//can go out of range
	//need to swap out the sprite when turning
	float carPos = playerCurvature - Track::trackCurvature;
	playerSprites.at(2).setPosition(
		sf::Vector2f(((GameGlobals::SCREEN_W/2)+ (carPos *GameGlobals::SCREEN_W) ) - playerSprites.at(2).getGlobalBounds().width / 2, (GameGlobals::SCREEN_H) - playerSprites.at(2).getGlobalBounds().height - 10));
}

void Racer::updateCurvature(float amount, bool add)
{
	
	if (add)
		playerCurvature += amount;
	else
		playerCurvature -= amount;


}

float Racer::getCurvature() { return playerCurvature; }