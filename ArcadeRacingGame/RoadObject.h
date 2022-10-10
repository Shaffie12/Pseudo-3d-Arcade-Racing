#ifndef _ROADOBJECT_H_
#define _ROADOBJECT_H_
#include "Drawable.h"

class RoadObject : public Drawable
{
public:
	RoadObject();
	RoadObject(RoadObject&& other);
	RoadObject(const RoadObject& other);
	~RoadObject();

	virtual void drawElement(sf::RenderTarget& w) override;
protected:
	float screen_y;
	sf::Texture texture;
	sf::Sprite sprite;
	



};
#endif