#ifndef _SEGMENT_H_
#define _SEGMENT_H_
#include "GameGlobals.h"



class Segment
{
	public:
		Segment(int id,float curve,float dist);
		int id;
		float curvature;
		float length;
		float screen_y = GameGlobals::GAME_H / 2;
		
		


};
#endif 

