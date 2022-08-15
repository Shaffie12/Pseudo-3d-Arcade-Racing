#include "Renderer.h"
#include "GameGlobals.h"

void Renderer::calculateCol(float xpos)
{}

void Renderer::drawLines(sf::RenderWindow& win)
{

	std::vector<Line> lines;

	//maybe these should be defined in the class too
	sf::Color grassDark(55, 154, 84);
	sf::Color road(178, 195, 183);

	float y;
	float mid = 0.5f;



	for (int i = 0; i <  screen_h/ 2; i++)
	{
		Line line;
		y = (screen_h / 2) + i; //middle of screen downward
		float perspective = 0.06 + ((y - (screen_h / 2)) / (screen_h - (screen_h / 2))) * 0.5f; //scaling the 300-600 values to values between 0-1
		tile_w = perspective * 0.5;

		//draw the vertices for the lines

		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, y), sf::Color::Green);
		line.vertices[1] = sf::Vertex(sf::Vector2f((mid - perspective - tile_w) * screen_w, y), sf::Color::Green); //is it because im drawing from grass straight to road?

		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f((mid - perspective - tile_w) * screen_w, y), sf::Color::Red);
		line.vertices[3] = sf::Vertex(sf::Vector2f((mid - perspective) * screen_w, y), sf::Color::Red);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f((mid - perspective) * screen_w, y), road);
		line.vertices[5] = sf::Vertex(sf::Vector2f((mid + perspective) * screen_w, y), road);

		//edge 2
		line.vertices[6] = sf::Vertex(sf::Vector2f((mid + perspective) * screen_w, y), sf::Color::Red);
		line.vertices[7] = sf::Vertex(sf::Vector2f((mid + perspective + tile_w) * screen_w, y), sf::Color::Red);

		//grass right
		line.vertices[8] = sf::Vertex(sf::Vector2f((mid + perspective + tile_w) * screen_w, y), sf::Color::Green);
		line.vertices[9] = sf::Vertex(sf::Vector2f(screen_w, y), sf::Color::Green);

		//add the line to list
		lines.push_back(line);

	}

	//draw the lines
	for (int i = 0; i < lines.size(); i++)
	{
		win.draw(lines.at(i).vertices, 10, sf::Lines);
	}


};
