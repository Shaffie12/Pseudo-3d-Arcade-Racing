#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "SFML/Graphics.hpp"
#include <vector>

enum direction { f, l, r }; //not sure where this should be

class Renderer
{
	public:
		Renderer(); 

		void drawLines(sf::RenderWindow& win);
		void drawSprites(sf::RenderWindow& win);
		

		//maybe static but im not sure if these need to be manipulated for the bends in the track later
		float road_w = 0.8f;
		float minRoad = 0.01; //minimal amount of road at the highest point on road
		float percentOfPersp = 0.5f; // change view toward ground or sky
		enum direction dir;

		void addDist(float amount); //why not use friend fn?
		float getDist();
		void updateTrackFocus(float amount, bool add);
		void changeDir(direction d);
		
		
	private:
		struct Line { sf::Vertex vertices[10]; };
		float tile_w = road_w * 0.15f;
		float dist = 0;
		float mid = 0.5f;

		//colours to use for the scene.
		sf::Color grassLight = sf::Color::Green;
		sf::Color grassDark = sf::Color(55, 154, 84);
		sf::Color roadLight = sf::Color(178, 195, 183);
		sf::Color roadDark = sf::Color(188, 205, 190);
		sf::Color tile_col_1 = sf::Color::Red;
		sf::Color tile_col_2 = sf::Color::White;

		sf::Texture playerTex;
		std::vector<sf::Sprite> playerSprites; //sprite sheet should probably be global somewhere or in the player class also not sure vector is the most mem efficient, since i know the size of the array



};

#endif 
