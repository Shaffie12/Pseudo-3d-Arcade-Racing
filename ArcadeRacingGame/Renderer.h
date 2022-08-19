#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "SFML/Graphics.hpp"
#include "Drawable.h"
#include <vector>



class Renderer
{
	public:
		Renderer(); 
		void draw(sf::RenderWindow& w, Drawable& d);
		
	private:



};

#endif 
