#include "RoadObject.h"
#include<iostream>


RoadObject::RoadObject() : activeSpr(&sprites[3])
{ 
	screen_y = GameGlobals::GAME_H / 2;
	spawnDist = 0;
	float scaledY = Racing::Util::convertRange(screen_y, 1, GameGlobals::GAME_H/2, 1, 0);
	perspective = Track::minRoad + 0.035+scaledY * Track::road_w;

	
};


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

void RoadObject::drawElement(sf::RenderTarget& w)
{
	move();
	w.draw(*activeSpr);

}

void RoadObject::move()
{
	screen_y += 0.7 * Track::speed;
	float scaledY = Racing::Util::convertRange(screen_y, GameGlobals::GAME_H/2, GameGlobals::GAME_H , 0, 1);
	perspective = Track::minRoad + scaledY * Track::road_w;
	//perspective += perspective * (Track::tile_w );
	//perspective -= perspective ;

	if (screen_y > 152)
		activeSpr = &sprites[2];
	if (screen_y > 155)
		activeSpr = &sprites[1];
	if (screen_y > 160)
		activeSpr = &sprites[0];

	activeSpr->setPosition(sf::Vector2f((0.5 + perspective) *GameGlobals::GAME_W+activeSpr->getGlobalBounds().width, screen_y - activeSpr->getGlobalBounds().height/2)); 
	
}

