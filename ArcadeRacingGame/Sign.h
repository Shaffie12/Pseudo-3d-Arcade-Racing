#ifndef _SIGN_H_
#define _SIGN_H_

#include "RoadObject.h"
#include "GameGlobals.h"

class Sign : public RoadObject
{
	public:
		Sign(int segmentId, float depth, bool left);
	
};
#endif