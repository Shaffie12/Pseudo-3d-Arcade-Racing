#ifndef _NPC_RACER_H_
#define _NPC_RACER_H_
#include "Racer.h"

class NpcRacer: public Racer
{
public:
	NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color =sf::Color::White);
	void update(const float& dt) override;
	const float distanceFromCenter() const;
	
private:
	float baseSpeed;
	void swapSprite();
	void scale();
	void position();
	int screenY;

	
};
#endif

