#ifndef _START_SIGN_H_
#define _START_SIGN_H_
#include "RoadObject.h"

class StartSign : public RoadObject
{
public:
	StartSign(int screeny, int segmentId, float depth, bool left);
	StartSign(int segmentId, float depth, bool left);
	void loadSprites() override;
};


#endif 
