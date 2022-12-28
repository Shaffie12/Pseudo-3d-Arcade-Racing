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
	RoadObject(int screeny, int segmentID, float depth, bool left);
	RoadObject(int segmentID, float depth, bool left);
	RoadObject(const RoadObject& other);
	RoadObject(RoadObject&& other) noexcept;
	RoadObject& operator=(const RoadObject& other);
	virtual void drawElement(sf::RenderTarget& w) override;
	virtual void update(float dt)override;
	float depth; //at what point relative to the segment progress down the screen, should we start drawing this object
	int segId;
	bool draw = false; //was doing this check in the racing game before
protected:
	bool left;
	float perspective;
	float screen_y;
	sf::Transform base_transform;
	static int slow_limiter;
	static int sprite_limits[3];
	sf::Texture texture;
	sf::Sprite sprites[4];
	sf::Sprite* activeSpr;
	
	void loadSprites();
	void swapSprite();
	void upscale();
	void move();
	void checkDraw();
	
	
};
#endif