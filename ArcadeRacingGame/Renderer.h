#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "SFML/Graphics.hpp"
#include <vector>

class Renderer
{
	public:
		Renderer(); 

		void drawLines(sf::RenderWindow& win);
		void calculateCol(float xpos);

		//maybe static but im not sure if these need to be manipulated for the bends in the track later
		float road_w = 0.8f; 
		
	private:
		struct Line { sf::Vertex vertices[10]; };
		float tile_w = road_w * 0.15f;


};

#endif // _RENDERER_H_
