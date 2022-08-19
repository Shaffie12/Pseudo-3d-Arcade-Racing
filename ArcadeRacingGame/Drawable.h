#ifndef DRAWABLE_H_
#define DRAWABLE_H_
#include <SFML/Graphics.hpp>


class Drawable
{
	public:
		virtual void drawElement(sf::RenderWindow& w) = 0;

};


#endif 

