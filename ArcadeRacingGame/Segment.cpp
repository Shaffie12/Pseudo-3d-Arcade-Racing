#include "Segment.h"

Segment::Segment(float curve, float dist, std::vector<std::pair<RoadObject, int>> objects) {
	screen_y = GameGlobals::GAME_H / 2;
	roadsides = objects; 
}