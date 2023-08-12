#ifndef _ROCK_H_
#define _ROCK_H_
#include "RoadObject.h"

class Rock : public RoadObject
{
public:
	Rock(int screeny, int segmentId, float depth, bool left, Track& t);
	Rock(int segmentId, float depth, bool left, Track& t);
};

#endif 

