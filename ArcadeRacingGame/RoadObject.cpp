#include "RoadObject.h"
#include<iostream>


RoadObject::RoadObject(bool left) : activeSpr(&sprites[3])
{ 
	screen_y = GameGlobals::GAME_H / 2;
	spawnDist = 0;
	this->left = left;	
	float scaledY = Racing::Util::convertRange(screen_y, 1, GameGlobals::GAME_H/2, 1, 0);
	perspective = Track::minRoad + 0.035+scaledY * Track::road_w;

	
};


RoadObject::RoadObject(RoadObject&& other) noexcept : activeSpr (&sprites[3])
{
	screen_y = other.screen_y;
	perspective = other.perspective;
	spawnDist=other.spawnDist;
	texture = other.texture;
	left = other.left;

	memcpy(sprites, other.sprites, sizeof(sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		sprites[i].setTexture(texture);
	other.activeSpr = nullptr;
	activeSpr = &sprites[3];
	
	
}

void RoadObject::drawElement(sf::RenderTarget& w)
{
	swapSprite();
	move();
	if(screen_y<GameGlobals::GAME_H)
		w.draw(*activeSpr);

}

void RoadObject::move()
{
	
	int idx = Track::lines.size() - 1;
	screen_y += 1 * Track::speed;
	idx = (screen_y - 150) < Track::lines.size() - 1 ? (screen_y -150) : idx;


	
	activeSpr->setPosition(sf::Vector2f(((Track::lines.at(idx).middlePt + Track::lines.at(idx).perspective )*GameGlobals::GAME_W)+activeSpr->getGlobalBounds().width, 
		screen_y - activeSpr->getGlobalBounds().height));
	
	
}

void::RoadObject::swapSprite()
{
	if (screen_y > 152)
		activeSpr = &sprites[2];
	if (screen_y > 155)
		activeSpr = &sprites[1];
	if (screen_y > 160)
		activeSpr = &sprites[0];
}
