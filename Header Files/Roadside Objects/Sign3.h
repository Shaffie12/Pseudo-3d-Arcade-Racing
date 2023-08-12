#ifndef _SIGN3_H_
#define _SIGN3_H_

#include "RoadObject.h"
#include "GameGlobals.h"

class Sign3 : public RoadObject
{
public:
	Sign3(int screeny, int segmentId, float depth, bool left, Track& t);
	Sign3(int segmentId, float depth, bool left, Track& t);
	void loadSprites() override;

};
#endif