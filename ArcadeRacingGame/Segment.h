#ifndef _SEGMENT_H_
#define _SEGMENT_H_
#include "RoadObject.h"



class Segment
{
	public:
		Segment(float curve,float dist,std::vector<std::pair<RoadObject,int>> objects);
		float curvature;
		float distance; //foppy does this by having a length instead, and decreasing the length as the player moves forward.  when len<=0 new segement is processed
		float screen_y = GameGlobals::GAME_H / 2;
		std::vector<std::pair<RoadObject,int>> roadsides; //all of the roadobj are draw at horizon to start, 
														//they each have a distance number indicating when to draw them
		


};
#endif 

