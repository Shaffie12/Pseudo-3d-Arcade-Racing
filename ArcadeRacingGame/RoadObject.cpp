#include "RoadObject.h"
#include<iostream>


RoadObject::RoadObject() : activeSpr(&sprites[3])
{ 
	screen_y = GameGlobals::GAME_H / 2;
	spawnDist = 0;	
	float scaledY = Racing::Util::convertRange(screen_y, 1, GameGlobals::GAME_H/2, 1, 0);
	perspective = Track::minRoad + 0.035+scaledY * Track::road_w;

	
};

RoadObject::RoadObject(const RoadObject& other)
{
	screen_y = other.screen_y;
	perspective = other.perspective;
	spawnDist = other.spawnDist;
	texture = other.texture;

	memcpy(sprites, other.sprites, sizeof(sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		sprites[i].setTexture(texture);
	activeSpr = &sprites[3];
}

RoadObject::RoadObject(RoadObject&& other) noexcept : activeSpr (&sprites[3])
{
	screen_y = other.screen_y;
	perspective = other.perspective;
	spawnDist=other.spawnDist;
	texture = other.texture;

	memcpy(sprites, other.sprites, sizeof(sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		sprites[i].setTexture(texture);
	other.activeSpr = nullptr;
	activeSpr = &sprites[3];
	
	
}

RoadObject& RoadObject::operator=(const RoadObject& other)
{
	RoadObject ro;
	ro.screen_y = other.screen_y;
	ro.perspective = other.perspective;
	ro.spawnDist = other.spawnDist;
	ro.texture = other.texture;

	memcpy(ro.sprites, other.sprites, sizeof(ro.sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		ro.sprites[i].setTexture(ro.texture);
	ro.activeSpr = &ro.sprites[3];
	return ro;
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
