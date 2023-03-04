#include "Sign.h"
#include<iostream>

Sign::Sign(int screeny, int segmentId, float depth, bool left, Track& t, bool invert): RoadObject(screeny, segmentId,depth, left,t,invert)
{
	if (!texture.loadFromFile("assets/roadside/signsheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();

	
}

Sign::Sign(int segmentId, float depth, bool left, Track& t, bool invert) : RoadObject(segmentId, depth, left,t, invert)
{
	if (!texture.loadFromFile("assets/roadside/signsheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
	
	

}






