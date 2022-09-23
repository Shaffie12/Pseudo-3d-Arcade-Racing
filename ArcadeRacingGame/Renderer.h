#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "SFML/Graphics.hpp"
#include "Drawable.h"
#include "GameGlobals.h"



class Renderer
{
	public:
		Renderer(); 
		Renderer(const Renderer& other);
		~Renderer();
		sf::RenderTexture* rtx;
		sf::Sprite* sprite;
		void init();
		
	private:



};

#endif 
