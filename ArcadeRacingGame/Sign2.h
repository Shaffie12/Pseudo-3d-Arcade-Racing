#ifndef _SIGN2_H_
#define _SIGN2_H_

#include "RoadObject.h"
#include "GameGlobals.h"

class Sign2 : public RoadObject
{
public:
	Sign2(int screeny, int segmentId, float depth, bool left, Track& t);
	Sign2(int segmentId, float depth, bool left, Track& t);

};
#endif