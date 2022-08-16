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
		float minRoad = 0.06f; //minimal amount of road at the highest point on road
		float percentOfPersp = 0.5f; // change view toward ground or sky

		void addDist(float amount); //why not use friend fn?
		float getDist();
		
		
	private:
		struct Line { sf::Vertex vertices[10]; };
		float tile_w = road_w * 0.15f;
		float dist = 0;


};

#endif // _RENDERER_H_
