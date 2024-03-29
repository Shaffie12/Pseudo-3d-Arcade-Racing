#ifndef _ROADOBJECT_H_
#define _ROADOBJECT_H_
#include "Drawable.h"
#include "Util.h"
#include "GameGlobals.h"
#include "Track.h"

class RoadObject : public Drawable
{
public:
	RoadObject(int screeny, int segmentID, float depth, bool left, Track& t, bool invert=false);
	RoadObject(int segmentID, float depth, bool left, Track& t, bool invert=false);
	RoadObject(const RoadObject& other);
	RoadObject(RoadObject&& other) noexcept;
	RoadObject& operator=(const RoadObject& other);
	sf::Vector2f getSpritePosition() { return activeSpr->getPosition(); }
	sf::FloatRect getSpriteSize() { return activeSpr->getGlobalBounds(); }
	virtual void drawElement(sf::RenderTarget& w) override;
	virtual void update(const float& dt) override;
	float depth; //at what point relative to the segment progress down the screen, should we start drawing this object
	int segId;
	bool draw = false; 
	float screen_y;
	bool left;
protected:
	Track& track;
	
	float perspective;
	sf::Transform base_transform;
	static int slow_limiter;
	static int sprite_limits[3];
	sf::Texture texture;
	sf::Sprite sprites[4];
	sf::Sprite* activeSpr;
	bool drawAtStart = false;
	bool invert = false;
	
	virtual void loadSprites();
	void swapSprite();
	void upscale();
	void move();
	void checkDraw();
	
	
};
#endif