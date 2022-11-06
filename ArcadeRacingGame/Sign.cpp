#include "Sign.h"
#include<iostream>

Sign::Sign(int segmentId, float depth, bool left): RoadObject(segmentId,depth, left)
{
	if (!texture.loadFromFile("assets/roadside/signsheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
	
}






