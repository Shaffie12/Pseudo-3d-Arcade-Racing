#ifndef _SEGMENT_H_
#define _SEGMENT_H_
#include "GameGlobals.h"



class Segment
{
	public:
		Segment(int id,float curve,float dist);
		int id;
		float curvature;
		float distance; //foppy does this by having a length instead, and decreasing the length as the player moves forward.  when len<=0 new segement is processed
		float screen_y = GameGlobals::GAME_H / 2;
		
		


};
#endif 

