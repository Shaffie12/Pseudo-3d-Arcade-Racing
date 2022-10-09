#include "RoadObject.h"
#include<iostream>


void RoadObject::drawElement(sf::RenderTarget& w)
{
	
	w.draw(sprite);
	//seems like invalid texture when used from parent class .  Works ok if i transfer variables to child
	
	
}