#include "Tree.h"

Tree::Tree(int screeny, int segmentId, float depth, bool left, Track& t): RoadObject(screeny, segmentId, depth, left,t)
{

	if (!texture.loadFromFile("assets/roadside/treesheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}

Tree::Tree(int segmentId, float depth, bool left, Track& t) : RoadObject(segmentId, depth, left, t)
{
	if (!texture.loadFromFile("assets/roadside/treesheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}
