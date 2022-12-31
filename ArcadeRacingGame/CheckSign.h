#ifndef CHECK_SIGN_H_
#define CHECK_SIGN_H_
#include "RoadObject.h"

class CheckSign : public RoadObject
{
public: 
	CheckSign(int screeny, int segmentId, float depth, bool left);
	CheckSign(int segmentId, float depth, bool left);
	void loadSprites() override;
};

#endif 