#include "Tree.h"

Tree::Tree(int segmentId, float depth, bool left): RoadObject(segmentId, depth, left)
{
	if (!texture.loadFromFile("assets/roadside/treesheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}
