#include "RoadObject.h"
#include<iostream>

int RoadObject::slow_limiter = 10;
int RoadObject::sprite_limits[3] = { 152,155,160 };

RoadObject::RoadObject(float depth, bool left) : activeSpr(&sprites[3])
{ 
	std::cout << "standard constructor was called" << '\n';
	this->left = left;
	screen_y = GameGlobals::GAME_H / 2;
	this->depth = depth;
	float scaledY = Racing::Util::convertRange(screen_y, 1, GameGlobals::GAME_H/2, 1, 0);
	perspective = Track::minRoad + 0.035+scaledY * Track::road_w;

	
};

RoadObject::RoadObject(const RoadObject& other) //copy
{
	std::cout << "copy constructor was called" << '\n';
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
	original_dimensions = sf::Vector2f(sprites[3].getLocalBounds().width, sprites[3].getLocalBounds().height);

}

RoadObject::RoadObject(RoadObject&& other) noexcept  //move 
{
	
	std::cout << "move constructor was called" << '\n';
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
	original_dimensions = sf::Vector2f(sprites[3].getLocalBounds().width, sprites[3].getLocalBounds().height);
	
	
	
}

RoadObject& RoadObject::operator=(const RoadObject& other) 
{
	RoadObject ro(other.depth, other.left);
	ro.screen_y = other.screen_y;
	ro.perspective = other.perspective;
	ro.left = other.left;
	ro.texture = other.texture;

	memcpy(ro.sprites, other.sprites, sizeof(ro.sprites));
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
		ro.sprites[i].setTexture(ro.texture);
	ro.activeSpr = &ro.sprites[3];
	ro.original_dimensions = sf::Vector2f(sprites[3].getLocalBounds().width, sprites[3].getLocalBounds().height);
	return ro;
}

void RoadObject::drawElement(sf::RenderTarget& w)
{
	
	swapSprite();
	upscale();
	move();
	w.draw(*activeSpr);

}

void RoadObject::move()
{
	float speed_scale = Racing::Util::convertRange(screen_y, 150, 200, 0.01f, 3); //scale the speed the object moves depending on proximity to bottom of screen
	int idx = Track::lines.size() - 1;
	screen_y += speed_scale * Track::speed;
	idx = (screen_y - 150) < Track::lines.size() - 1 ? (screen_y -150) : idx; //the list of lines is 149 long

	if (left)
		activeSpr->setPosition(sf::Vector2f(((Track::lines.at(idx).middlePt - Track::lines.at(idx).perspective) * GameGlobals::GAME_W) - activeSpr->getGlobalBounds().width,
			screen_y - activeSpr->getGlobalBounds().height));
	else
		activeSpr->setPosition(sf::Vector2f(((Track::lines.at(idx).middlePt + Track::lines.at(idx).perspective) * GameGlobals::GAME_W) + activeSpr->getGlobalBounds().width,
			screen_y - activeSpr->getGlobalBounds().height));

	

	
	
}

void::RoadObject::swapSprite() 
{
	
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
	float scale = Racing::Util::convertRange(screen_y, 150, 160, 1, 1.5f);
	activeSpr->setScale(scale, scale);

}
