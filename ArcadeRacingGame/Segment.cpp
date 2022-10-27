#include "Segment.h"

Segment::Segment(float curve, float dist) : screen_y(GameGlobals::GAME_H / 2)
{
	curvature = curve;
	distance = dist;
}