#ifndef TRACK_H_
#define TRACK_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include <SFML/Graphics.hpp>
#include<vector>

class Track :public Drawable
{
	
	public:
	void drawElement(sf::RenderWindow& w);
	void offsetCenter(float amount, bool add);
	
	
	private:
	struct Line { sf::Vertex vertices[10]; };

	float road_w = 0.8f;
	float tile_w = road_w * 0.15f;
	float mid = 0.5f;
	float minRoad = 0.01; //minimal amount of road at the highest point on road
	float percentOfPersp = 0.5f; // change view toward ground or sky

	sf::Color grassLight = sf::Color::Green;
	sf::Color grassDark = sf::Color(55, 154, 84);
	sf::Color roadLight = sf::Color(178, 195, 183);
	sf::Color roadDark = sf::Color(188, 205, 190);
	sf::Color tile_col_1 = sf::Color::Red;
	sf::Color tile_col_2 = sf::Color::White;

	
};


#endif
