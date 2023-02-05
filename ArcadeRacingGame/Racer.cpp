#include "Racer.h"
#include <iostream>

Racer::Racer(Track& t, sf::Vector2f startPosition, sf::Color color) : track(t)
{
	int pixStart = 0;
	for (int i = 0; i < 5; i++)
	{
		racerSprites.push_back(sf::Sprite(ImageManager::GetInstance()->carTexture, sf::IntRect(pixStart, 0, 32, 16)));
		pixStart += 32;
		racerSprites.at(i).scale(sf::Vector2f(2,2));
		racerSprites.at(i).setPosition(
			sf::Vector2f((startPosition.x) - racerSprites.at(i).getGlobalBounds().width / 2, (startPosition.y) - racerSprites.at(i).getGlobalBounds().height - 10));
		racerSprites.at(i).setColor(color);
	}
	activeSprite = &racerSprites.at(2);

	for (int i = 0; i < sizeof(explosions) / sizeof(sf::Sprite); i++)
	{
		explosions[i].setTexture(ImageManager::GetInstance()->deathTextures[i]);
		explosions[i].setPosition(sf::Vector2f((startPosition.x) - explosions[i].getGlobalBounds().width / 2, (startPosition.y) - explosions[i].getGlobalBounds().height - 10));
		explosions[i].setScale(sf::Vector2f(2, 2));
		explosions[i].setColor(sf::Color::Transparent);
	}
}

void Racer::drawElement(sf::RenderTarget& w)
{
	w.draw(*activeSprite);
	w.draw(explosions[drawExplosionIdx]);
}

void Racer::update(const float& dt)
{
	if(!dead)
	{

		activeSprite->setPosition(
			sf::Vector2f((GameGlobals::GAME_W / 2) - activeSprite->getGlobalBounds().width / 2,
				(GameGlobals::GAME_H)-activeSprite->getGlobalBounds().height - 10));
	}
	else
	{

		OnDestroy();
		explosions[drawExplosionIdx].setPosition(
			sf::Vector2f((GameGlobals::GAME_W / 2) - explosions[drawExplosionIdx].getGlobalBounds().width / 2,
				(GameGlobals::GAME_H)-explosions[drawExplosionIdx].getGlobalBounds().height - 10));
	}
}

void Racer::Destroy()
{
	dead = true;
	activeSprite = &racerSprites.at(0);
	clock.restart();
}

void Racer::OnDestroy()
{
	if (clock.getElapsedTime().asSeconds() >= 0.1f && clock.getElapsedTime().asSeconds() <= 0.5f)
	{
		explosions[drawExplosionIdx].setColor(sf::Color::White);
		activeSprite->setColor(sf::Color::Transparent);

	}
	else if (clock.getElapsedTime().asSeconds() > 0.5f)
	{
		for (sf::Sprite s : explosions)
			s.setColor(sf::Color::Transparent);
		
		activeSprite = &racerSprites.at(2);

		dead = false;
	}
		
}

float Racer::distanceToTrackEdge()
{
	return std::abs(track.lines.at(track.lines.size() - 1).middlePt * GameGlobals::GAME_W - GameGlobals::GAME_W / 2);
}

