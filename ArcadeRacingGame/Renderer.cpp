#include "Renderer.h"
#include "GameGlobals.h"
#include <iostream>
#include "Util.h"

Renderer::Renderer() 
{ 
	
	dir = f; //want to move these to a player class

	playerTex.loadFromFile("assets/car.png");
	int pixStart = 0;
	for (int i = 0; i<5; i++) 
	{
		playerSprites.push_back( sf::Sprite(playerTex, sf::IntRect(pixStart, 0, 32, 16)));
		pixStart += 32;
		playerSprites.at(i).scale(sf::Vector2f(3, 3));
		playerSprites.at(i).setPosition(sf::Vector2f((GameGlobals::SCREEN_W / 2) - playerSprites.at(i).getGlobalBounds().width / 2, (GameGlobals::SCREEN_H)-playerSprites.at(i).getGlobalBounds().height - 10));
	}

}




void Renderer::drawLines(sf::RenderWindow& win)
{

	std::vector<Line> lines;
	float y;
	

	//construct the lines
	for (int i = 0; i <  GameGlobals::SCREEN_H/ 2; i++)
	{
		Line line;
		y = (GameGlobals::SCREEN_H / 2) + i; //middle of screen downward

		//scaling the 300-600 values to values between 0-1
		float perspective = minRoad + ((y - (GameGlobals::SCREEN_H / 2)) / (GameGlobals::SCREEN_H - (GameGlobals::SCREEN_H / 2))) * percentOfPersp; 
		tile_w = perspective * 0.2;

		sf::Color grassCol = sinf(15 * pow(1 - perspective, 10) + dist * 0.1) > 0.0f ? grassLight : grassDark;
		sf::Color tileCol = sinf(50 * pow(1 - perspective, 5) + dist * 0.7) > 0.0f ? tile_col_1 : tile_col_2;
		sf::Color roadCol = sinf(50 * pow(1 - perspective, 5) + dist * 0.7) > 0.0f ? roadLight : roadDark;
		//lerp rgb value for single vertex on the road to create approaching gradient?
		

		//draw the vertices for the lines

		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, y),grassCol);
		line.vertices[1] = sf::Vertex(sf::Vector2f((mid - perspective - tile_w) * GameGlobals::SCREEN_W, y), grassCol); 
		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f((mid - perspective - tile_w) * GameGlobals::SCREEN_W, y), tileCol);
		line.vertices[3] = sf::Vertex(sf::Vector2f((mid - perspective) * GameGlobals::SCREEN_W, y), tileCol);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f((mid - perspective) * GameGlobals::SCREEN_W, y), roadCol);
		line.vertices[5] = sf::Vertex(sf::Vector2f((mid + perspective) * GameGlobals::SCREEN_W, y), roadLight);

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

void Renderer::drawSprites(sf::RenderWindow& win)
{
	win.draw(playerSprites.at(2));//can go out of range
}

void::Renderer::addDist(float amount) { dist += amount; }
float::Renderer::getDist() { return dist; }
void Renderer::updateTrackFocus(float amount, bool add)
{
	if (add)
		mid += amount;
	else
		mid -= amount;
}
void Renderer::changeDir(direction d) { dir = d; }

//draw fn with 2 overrides (Idrawable, vector<Idrawable>)
//calls win.draw or for each ..win.draw
//the objects classes to be drawn such as road, tree, sky, player can have a sprite or list of vertices
//and a function which returns the thing to be drawn (Idrawable)

//in terms of a player class which exists for more than just to be drawn, it needs to know direction so that its sprite can be updated.
//the size of the other sprites (and AI cars) needs to be scaled according to the road/distance or some other speed variable