#ifndef _ROADOBJECT_H_
#define _ROADOBJECT_H_
#include "Drawable.h"

class RoadObject : public Drawable
{
public:
	
	void drawElement(sf::RenderTarget& w);
protected:
	float screen_y;
	sf::Texture texture;
	sf::Sprite sprite;
	//std::vector<sf::Texture> textures;
	//std::vector<sf::Sprite> sprites;



};
#endif