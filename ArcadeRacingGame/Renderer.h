#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "SFML/Graphics.hpp"
#include <vector>

class Renderer
{
	public:
		Renderer(); 
		static void drawLines(sf::RenderWindow& win);
		static void calculateCol(float xpos);

		//maybe static but im not sure if these need to be manipulated for the bends in the track later
		float road_w = 0.8f; 
		float tile_w = road_w * 0.15f;

	private:
		struct Line { sf::Vertex vertices[10]; };


};

#endif // _RENDERER_H_
