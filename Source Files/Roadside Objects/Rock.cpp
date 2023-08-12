#include "Rock.h"

Rock::Rock(int screeny, int segmentId, float depth, bool left, Track& t) :RoadObject(screeny, segmentId,depth,left,t)
{
	
	if (!texture.loadFromFile("assets/roadside/rocksheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}

Rock::Rock(int segmentId, float depth, bool left, Track& t) :RoadObject(segmentId, depth, left, t)
{

	if (!texture.loadFromFile("assets/roadside/rocksheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}