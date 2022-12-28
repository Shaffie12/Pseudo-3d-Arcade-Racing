#include "RoadObject.h"
#include<iostream>

int RoadObject::slow_limiter = 10;
int RoadObject::sprite_limits[3] = { 152,155,160 };

RoadObject::RoadObject(int screeny, int segmentId, float depth, bool left) : activeSpr(&sprites[3]), segId(segmentId)
{ 
	//std::cout << "standard constructor was called" << '\n';
	this->left = left;
	if (screeny < GameGlobals::GAME_H / 2)
		screen_y = GameGlobals::GAME_H / 2;
	else
		screen_y = screeny;
	this->depth = depth;
	float scaledY = Racing::Util::convertRange(screen_y, 1, GameGlobals::GAME_H/2, 1, 0);
	perspective = Track::minRoad + 0.035+scaledY * Track::road_w;

	
};

RoadObject::RoadObject(int segmentId, float depth, bool left) : activeSpr(&sprites[3]), segId(segmentId)
{
	//std::cout << "standard constructor was called" << '\n';
	this->left = left;
	screen_y = GameGlobals::GAME_H / 2;
	this->depth = depth;
	float scaledY = Racing::Util::convertRange(screen_y, 1, GameGlobals::GAME_H / 2, 1, 0);
	perspective = Track::minRoad + 0.035 + scaledY * Track::road_w;


};

RoadObject::RoadObject(const RoadObject& other) //copy
{
	//std::cout << "copy constructor was called" << '\n';
	segId = other.segId;
	draw = other.draw;
	left = other.left;
	screen_y = other.screen_y;
	perspective = other.perspective;
	depth = other.depth;
	sf::Image img = other.texture.copyToImage();
	texture.loadFromImage(img);


	memcpy(sprites, other.sprites, sizeof(sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		sprites[i].setTexture(texture);
	activeSpr = &sprites[3];
	base_transform = sprites[3].getTransform();

}

RoadObject::RoadObject(RoadObject&& other) noexcept  //move 
{
	
	//std::cout << "move constructor was called" << '\n';
	segId = other.segId;
	draw = other.draw;
	left = other.left;
	screen_y = other.screen_y;
	perspective = other.perspective;
	depth=other.depth;
	texture.swap(other.texture);

	memcpy(sprites, other.sprites, sizeof(sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		sprites[i].setTexture(texture);
	other.activeSpr = nullptr;
	activeSpr = &sprites[3];
	base_transform = base_transform = sprites[3].getTransform();
	
	
	
}

RoadObject& RoadObject::operator=(const RoadObject& other) 
{
	RoadObject ro(other.segId, other.depth, other.left);
	ro.screen_y = other.screen_y;
	ro.draw = other.draw;
	ro.perspective = other.perspective;
	ro.left = other.left;
	ro.texture = other.texture;

	memcpy(ro.sprites, other.sprites, sizeof(ro.sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		ro.sprites[i].setTexture(ro.texture);
	ro.activeSpr = &ro.sprites[3];
	ro.base_transform = sprites[3].getTransform();
	return ro;
}

void RoadObject::update(float dt){}

void RoadObject::drawElement(sf::RenderTarget& w)
{
	checkDraw();
	if (draw)
	{
		swapSprite();
		move();
		upscale();
		w.draw(*activeSpr);
	}	

}

void RoadObject::move()
{

	float acceleration_scale = Racing::Util::convertRange(screen_y, 150, 200, 0.01f, 3); //scale the acceleration the object moves depending on proximity to bottom of screen
	int idx = Track::lines.size() - 1;
	screen_y += acceleration_scale * Track::acceleration;
	idx = (screen_y - 150) < Track::lines.size() - 1 ? (screen_y -150) : idx; //the list of lines is 149 element long

	
	if (left)
		activeSpr->setPosition(sf::Vector2f(((Track::lines.at(idx).middlePt - Track::lines.at(idx).perspective) * GameGlobals::GAME_W) - activeSpr->getGlobalBounds().width,
			screen_y - activeSpr->getGlobalBounds().height));
	else
		activeSpr->setPosition(sf::Vector2f(((Track::lines.at(idx).middlePt + Track::lines.at(idx).perspective) * GameGlobals::GAME_W) + activeSpr->getGlobalBounds().width,
			screen_y - activeSpr->getGlobalBounds().height));
		
}

void::RoadObject::swapSprite() 
{
	if (screen_y < sprite_limits[0])
		activeSpr = &sprites[3];
	if (screen_y > sprite_limits[0])
		activeSpr = &sprites[2];
	if (screen_y > sprite_limits[1])
		activeSpr = &sprites[1];
	if (screen_y > sprite_limits[2])
		activeSpr = &sprites[0];
	
	
	upscale();
	
}

void::RoadObject::upscale()
{
	float scale = Racing::Util::roundToDP(Racing::Util::convertRange(screen_y, 150, 160, 0.5f, 1),1);
	activeSpr->setScale(scale, scale);

	//may have to replace it with a copy that has the original transform scaled instead (only way to get original dimensions)

}

void RoadObject::checkDraw()
{
	if (segId == Track::activeSeg->id && depth <= Track::activeSeg->screen_y - 150)
		draw = true;
	if (screen_y > 300 && Track::activeSeg->id!= segId)
	{
		draw = false;
		screen_y = GameGlobals::GAME_H / 2;
	}
		

}

void RoadObject::loadSprites()
{
	int ix = 0;
	int iy = 0;
	int size = 32;
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
	{
		sprites[i] = sf::Sprite(texture, sf::IntRect(ix, iy, size, size));
		sprites[i].setPosition(sf::Vector2f((0.5 + perspective + Track::tile_w) * GameGlobals::GAME_W, screen_y - activeSpr->getGlobalBounds().height / 2));
		ix += size;
		iy += 8;
		size -= 8;
		sprites[i].setOrigin(sf::Vector2f(sprites[i].getGlobalBounds().width / 2, 0));
	}

	//reassign default
	activeSpr = &sprites[3];
	base_transform = sprites[3].getTransform();
}

