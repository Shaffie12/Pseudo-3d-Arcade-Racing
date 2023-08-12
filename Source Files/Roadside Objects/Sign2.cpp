#include "Sign2.h"

Sign2::Sign2(int screeny, int segmentId, float depth, bool left, Track& t) : RoadObject(screeny, segmentId, depth, left, t)
{
	if (!texture.loadFromFile("assets/roadside/sign2sheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}

Sign2::Sign2(int segmentId, float depth, bool left, Track& t) : RoadObject(segmentId, depth, left, t)
{
	if (!texture.loadFromFile("assets/roadside/sign2sheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}
