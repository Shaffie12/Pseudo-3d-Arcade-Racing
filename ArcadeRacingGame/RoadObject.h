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
	RoadObject(float depth, bool left);
	RoadObject(const RoadObject& other);
	RoadObject(RoadObject&& other) noexcept;
	RoadObject& operator=(const RoadObject& other);
	virtual void drawElement(sf::RenderTarget& w) override;
	float depth; //at what point should we start drawing this object
protected:
	bool left;
	float perspective;
	float screen_y;
	sf::Vector2f original_dimensions;
	static int slow_limiter;
	static int sprite_limits[3];
	sf::Texture texture;
	sf::Sprite sprites[4];
	sf::Sprite* activeSpr;
	
	void swapSprite();
	void upscale();
	void move();
	
};
#endif