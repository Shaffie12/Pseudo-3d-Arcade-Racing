#ifndef _NPC_RACER_H_
#define _NPC_RACER_H_
#include "Racer.h"

class NpcRacer: public Racer
{
public:
	NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color =sf::Color::White);
	void update(const float& dt) override;
	const float distanceFromCenter(int& screenYPos) const;
private:
	float speed;
	void swapSprite();
	void scale();
	int screenY;
	
};
#endif

