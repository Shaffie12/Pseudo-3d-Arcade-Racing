#ifndef _START_SIGN_H_
#define _START_SIGN_H_
#include "RoadObject.h"

class StartSign : public RoadObject
{
public:
	
	StartSign(int screeny, int segmentId, float depth, bool left, Track& t);
	StartSign(int segmentId, float depth, bool left,Track& t);
	void loadSprites() override;
	void update(const float& dt) override;
	void checkSwapTexture();
private:
	int currentTexture = 0;
	sf::Texture checkTexture; //1
	sf::Texture goalTexture; //2
};


#endif 
