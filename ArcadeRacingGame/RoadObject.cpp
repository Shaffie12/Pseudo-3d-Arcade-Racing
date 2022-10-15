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
	swapSprite();
	//prolly need to use differnet number for index so can keep moving the sprite down past bottom without std out of range
	screen_y = screen_y-150 < Track::lines.size()-1 ? screen_y + 1 *Track::speed : screen_y;
	activeSpr->setPosition(sf::Vector2f(Track::lines.at((int)screen_y - Track::lines.size()).middlePt *GameGlobals::GAME_W, screen_y - activeSpr->getGlobalBounds().height));
	

	/*
	screen_y += 0.7 * Track::speed;
	float scaledY = Racing::Util::convertRange(screen_y, GameGlobals::GAME_H/2, GameGlobals::GAME_H , 0, 1);
	perspective = Track::minRoad + scaledY * Track::road_w;
	//perspective += perspective * (Track::tile_w );
	//perspective -= perspective ;

	

	activeSpr->setPosition(sf::Vector2f((0.5 + perspective) *GameGlobals::GAME_W+activeSpr->getGlobalBounds().width, screen_y - activeSpr->getGlobalBounds().height/2)); 
	*/
	
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
