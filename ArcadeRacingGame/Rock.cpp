#include "Rock.h"

Rock::Rock(int screeny, int segmentId, float depth, bool left) :RoadObject(screeny, segmentId,depth,left)
{
	if (!texture.loadFromFile("assets/roadside/rocksheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}

Rock::Rock(int segmentId, float depth, bool left) :RoadObject(segmentId, depth, left)
{
	if (!texture.loadFromFile("assets/roadside/rocksheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}