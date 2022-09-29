#ifndef DRAWABLE_H_
#define DRAWABLE_H_
#include <SFML/Graphics.hpp>


class Drawable
{
	protected:
		virtual void drawElement(sf::RenderTarget& w) = 0;
		//virtual void update() = 0;
		

};


#endif 

