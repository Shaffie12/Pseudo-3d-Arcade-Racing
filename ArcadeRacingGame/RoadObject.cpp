#include "RoadObject.h"
#include<iostream>


RoadObject::RoadObject() {};
RoadObject::RoadObject(const RoadObject& other) 
{
	screen_y = other.screen_y;
	texture = other.texture;
	sprite = other.sprite;
	std::cout << "copied!" << '\n';
}

RoadObject::RoadObject(RoadObject&& other)
{
	texture = other.texture;
	sprite = other.sprite;

	std::cout << "moved!" << '\n';

}

RoadObject::~RoadObject() 
{
	std::cout << "destroyed!" << '\n'; 
}

void RoadObject::drawElement(sf::RenderTarget& w)
{
	
	w.draw(sprite);

	
}

