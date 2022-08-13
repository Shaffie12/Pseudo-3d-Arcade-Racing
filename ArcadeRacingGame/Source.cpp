
#include "SFML/Graphics.hpp"
#include <vector>

const int screen_w = 1000;
int screen_h = 600;
float road_w = screen_w * 0.8f;
float tile_w = road_w * 0.1f;
float depth = 1;

struct Line
{
	sf::Vertex vertices[10];
	Line() {};
	

};


void drawLines(sf::RenderWindow& window)
{ 
	
	std::vector<Line> lines;

	sf::Color grassDark(55, 154, 84);
	sf::Color road(178, 195, 183);

	for (int i = 0; i < screen_h / 2; i++)
	{
		Line line;
		float y = (screen_h - i) / screen_h / 2;
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, screen_h - i), sf::Color::Green);
		line.vertices[1] = sf::Vertex(sf::Vector2f(screen_w-road_w, (screen_h - i) / screen_h / 2), sf::Color::Green);

		line.vertices[2] = sf::Vertex(sf::Vector2f(screen_w - road_w, screen_h-i), road);
		line.vertices[3] = sf::Vertex(sf::Vector2f(road_w, screen_h-i), road);

		line.vertices[4] = sf::Vertex(sf::Vector2f(road_w, screen_h - i), sf::Color::Green);
		line.vertices[5] = sf::Vertex(sf::Vector2f(screen_w, screen_h - i), sf::Color::Green);


		lines.push_back(line);
		
	}

	/*
	sf::Vertex vertices[10] =
	{
		sf::Vertex(sf::Vector2f(0,screen_h - 50),sf::Color::Green),
		sf::Vertex(sf::Vector2f(screen_w-roadLStart,screen_h - 50),sf::Color::Green),

		sf::Vertex(sf::Vector2f(screen_w-roadLStart,screen_h-50),sf::Color::White),
		sf::Vertex(sf::Vector2f(roadLStart,screen_h-50),sf::Color::White),

		sf::Vertex(sf::Vector2f(roadLStart,screen_h-50),sf::Color::Green),
		sf::Vertex(sf::Vector2f(screen_w,screen_h-50),sf::Color::Green),

	};
	*/

	for (int i = 0; i < lines.size(); i++)
	{
		window.draw(lines.at(i).vertices, 2, sf::Lines);
	}


	//window.draw(vertices,6,sf::Lines);

};








int main()
{

	sf::RenderWindow w(sf::VideoMode(screen_w,screen_h), "Arcade Racing");
	sf::Event e;
	while (w.isOpen())
	{
		while (w.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				w.close();
		}
		w.clear();
		
		drawLines(w);
		w.display();
			
	}
	

	
	

	return 0;
}