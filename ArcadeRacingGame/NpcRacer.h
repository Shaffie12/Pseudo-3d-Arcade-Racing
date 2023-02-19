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
	const int spritesX[7] = { 29,29,23,23,13,9,7 };
	const int spritesY[7] = { 0,0,4,4,9,11,12 };
	const int spritesAcross[7] = { 29,29,23,23,13,9,7 };
	const int spritesDown[7] = { 16,16,12,12,7,5,4 };
	float speed;
	void swapSprite();
	void scale();
	void position();
	int screenY;
	void loadSprites(sf::Vector2f startPosition, sf::Color color);

	
};
#endif

