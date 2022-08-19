#ifndef PLAYER_H_
#define PLAYER_H_
#include "Racer.h"

class Player : public Racer
{
	public:
		Player();
		void addDist(float amount);
		float getDist();

	private:
		float dist;
};
#endif 
