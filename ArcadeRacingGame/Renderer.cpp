#include "Renderer.h"
#include "GameGlobals.h"
#include <iostream>

Renderer::Renderer() {}

void Renderer::calculateCol(float xpos)
{}

void Renderer::drawLines(sf::RenderWindow& win)
{

	std::vector<Line> lines;

	//maybe these should be defined in the class too
	

	float y;
	float mid = 0.5f;


	//construct the lines
	for (int i = 0; i <  GameGlobals::SCREEN_H/ 2; i++)
	{
		Line line;
		y = (GameGlobals::SCREEN_H / 2) + i; //middle of screen downward

		//scaling the 300-600 values to values between 0-1
		float perspective = minRoad + ((y - (GameGlobals::SCREEN_H / 2)) / (GameGlobals::SCREEN_H - (GameGlobals::SCREEN_H / 2))) * percentOfPersp; 
		tile_w = perspective * 0.5;

		sf::Color grassCol = sinf(15 * pow(1 - perspective, 10) + dist * 0.1) > 0.0f ? grassLight : grassDark;
		sf::Color tileCol = sinf(40 * pow(1 - perspective, 10) + dist * 0.7) > 0.0f ? tile_col_1 : tile_col_2;
		

		//draw the vertices for the lines

		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, y),grassCol);
		line.vertices[1] = sf::Vertex(sf::Vector2f((mid - perspective - tile_w) * GameGlobals::SCREEN_W, y), grassCol); //is it because im drawing from grass straight to road?

		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f((mid - perspective - tile_w) * GameGlobals::SCREEN_W, y), tileCol);
		line.vertices[3] = sf::Vertex(sf::Vector2f((mid - perspective) * GameGlobals::SCREEN_W, y), tileCol);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f((mid - perspective) * GameGlobals::SCREEN_W, y), roadCol);
		line.vertices[5] = sf::Vertex(sf::Vector2f((mid + perspective) * GameGlobals::SCREEN_W, y), roadCol);

		//edge 2
		line.vertices[6] = sf::Vertex(sf::Vector2f((mid + perspective) * GameGlobals::SCREEN_W, y), tileCol);
		line.vertices[7] = sf::Vertex(sf::Vector2f((mid + perspective + tile_w) *GameGlobals::SCREEN_W, y), tileCol);

		//grass right
		line.vertices[8] = sf::Vertex(sf::Vector2f((mid + perspective + tile_w) * GameGlobals::SCREEN_W, y), grassCol);
		line.vertices[9] = sf::Vertex(sf::Vector2f(GameGlobals::SCREEN_W, y), grassCol);

		//add the line to list
		lines.push_back(line);

	}

	//draw the lines on screen
	for (int i = 0; i < lines.size(); i++)
	{
		
		win.draw(lines.at(i).vertices, 10, sf::Lines);
		
	}


};

void::Renderer::addDist(float amount) { dist += amount; }
float::Renderer::getDist() { return dist; }
