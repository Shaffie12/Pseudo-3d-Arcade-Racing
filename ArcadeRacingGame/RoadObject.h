#ifndef _ROADOBJECT_H_
#define _ROADOBJECT_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Track.h"


class RoadObject : public Drawable
{
public:
	RoadObject();
	RoadObject(RoadObject&& other) noexcept;
	virtual void drawElement(sf::RenderTarget& w) override;
protected:
	float spawnDist;
	float perspective;
	float screen_y;
	sf::Texture texture;
	sf::Sprite sprites[4];
	sf::Sprite* activeSpr;


	void move();
	
};
#endif