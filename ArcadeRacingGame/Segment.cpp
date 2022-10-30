#include "Segment.h"

Segment::Segment(int id,float curve, float dist) : screen_y(GameGlobals::GAME_H / 2)
{
	this->id = id;
	curvature = curve;
	distance = dist;
}