#ifndef _SEGMENT_H_
#define _SEGMENT_H_
#include "GameGlobals.h"
#include "Util.h"
#include "RoadObject.h"

class Segment
{
	public:
		Segment(float curve,std::vector<RoadObject> objects);
private:
		float curvature;
		float distance; //foppy does this by having a length instead, and decreasing the length as the player moves forward.  when len<=0 new segement is processed
		float screen_y;
		std::vector<RoadObject> roadsides;
		


};
#endif 

