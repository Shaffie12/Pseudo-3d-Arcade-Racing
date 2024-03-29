#include "Racer.h"
#include <iostream>

Racer::Racer(Track& t, sf::Vector2f startPosition, sf::Color color ) : track(t)
{
	loadSprites(startPosition,color);
}

void Racer::drawElement(sf::RenderTarget& w)
{
	w.draw(*activeSprite);
	w.draw(explosions[drawExplosionIdx]);
}


void Racer::update(const float& dt)
{
	activeSprite->setPosition(
		sf::Vector2f((GameGlobals::GAME_W / 2) - activeSprite->getGlobalBounds().width / 2,
			(GameGlobals::GAME_H)-activeSprite->getGlobalBounds().height - 10));
	if(dead)
	{
		OnDestroy();
		if (dead)
		{
			OnDestroy();
			sf::Vector2f center(activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2, activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2);
			explosions[drawExplosionIdx].setPosition(
				sf::Vector2f(center.x - explosions[drawExplosionIdx].getGlobalBounds().width/2,center.y - explosions[drawExplosionIdx].getGlobalBounds().height + 17));
		}
	}

}

void Racer::Destroy()
{
	SoundManager::GetInstance()->explosion.play();
	dead = true;
	sf::Vector2f center = activeSprite->getPosition();
	activeSprite = &racerSprites.at(0);
	activeSprite->setPosition(
		sf::Vector2f(center.x ,center.y));
	clock.restart();
}
	

void Racer::OnDestroy()
{
	if (clock.getElapsedTime().asSeconds() >= 0.1f && clock.getElapsedTime().asSeconds() <= 1.0f)
	{
		activeSprite->setColor(sf::Color::White);
		if (clock.getElapsedTime().asSeconds() < 0.4f)
			drawExplosionIdx = 1;
		else
			drawExplosionIdx = 2;
		explosions[drawExplosionIdx].setColor(sf::Color::White);
	}
	else if (clock.getElapsedTime().asSeconds() > 2.0f)
	{
		for (sf::Sprite& s : explosions)
			s.setColor(sf::Color::Transparent);
		for (sf::Sprite& s : racerSprites)
			s.setColor(sf::Color::White);
		activeSprite = &racerSprites.at(2);

		dead = false;
	}
	else
		activeSprite->setColor(sf::Color::White);
		
}

void Racer::loadSprites(sf::Vector2f startPosition, sf::Color color)
{
	int pixStart = 0;
	for (int i = 0; i < 5; i++)
	{
		racerSprites.push_back(sf::Sprite(ImageManager::GetInstance()->carTexture, sf::IntRect(pixStart, 0, 32, 16)));
		pixStart += 32;
		racerSprites.at(i).scale(sf::Vector2f(2, 2));
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

float Racer::distanceFromCenter()
{
	float x = getSpritePosition().x + getSpriteSize().width / 2;
	int y = getSpritePosition().y - 150 + getSpriteSize().height;
	float plXDist = x - (track.lines.at(y).middlePt * GameGlobals::GAME_W);
	return plXDist;
	
}



