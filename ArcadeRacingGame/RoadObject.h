#ifndef _ROADOBJECT_H_
#define _ROADOBJECT_H_
#include "Drawable.h"
#include "Util.h"
#include "GameGlobals.h"
#include "Track.h"

class Track;



class RoadObject : public Drawable
{
public:
	RoadObject(float spawnDist);
	RoadObject(RoadObject&& other) noexcept;
	virtual void drawElement(sf::RenderTarget& w) override;
	bool draw;
protected:
	void swapSprite();
	float spawnDist;
	float perspective;
	float screen_y;
	sf::Texture texture;
	sf::Sprite sprites[4];
	sf::Sprite* activeSpr;
	


	void move();
	
};
#endif