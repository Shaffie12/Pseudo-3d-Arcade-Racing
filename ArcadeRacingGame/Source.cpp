
#include "SFML/Graphics.hpp"
#include <vector>
#include<iostream>

const int screen_w = 1000;
int screen_h = 600;
float road_w = 0.8f;
float tile_w = road_w * 0.15f;


struct Line
{
	
	sf::Vertex vertices[10];
	Line() { };
	

};


void drawLines(sf::RenderWindow& window)
{ 
	
	std::vector<Line> lines;

	sf::Color grassDark(55, 154, 84);
	sf::Color road(178, 195, 183);

	float y;
	float mid = 0.5f;
	


	for (int i = 0; i < screen_h / 2; i++)
	{
		Line line;
		y = (screen_h / 2) + i; //600 --> 300
		float perspective =  0.1+((y - (screen_h / 2)) / (screen_h - (screen_h / 2))); //scaling the 300-600 values to values between 0-1
		tile_w = perspective * 0.5; //fix!!
		
		//draw the vertices for the lines
		
		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, y), sf::Color::Green);
		line.vertices[1] = sf::Vertex(sf::Vector2f( (mid - perspective - tile_w)  * screen_w, y), sf::Color::Green); //is it because im drawing from grass straight to road?

		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f( (mid - perspective - tile_w) * screen_w, y), sf::Color::Red);
		line.vertices[3] = sf::Vertex(sf::Vector2f( (mid - perspective ) * screen_w, y), sf::Color::Red);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f( (mid - perspective) * screen_w, y), road);
		line.vertices[5] = sf::Vertex(sf::Vector2f(  (mid + perspective)  * screen_w , y), road);

		line.vertices[6] = sf::Vertex(sf::Vector2f( (mid + perspective ) *screen_w, y), sf::Color::Red);
		line.vertices[7] = sf::Vertex(sf::Vector2f( (mid + perspective + tile_w) *screen_w, y), sf::Color::Red);

		//grass right
		line.vertices[8] = sf::Vertex(sf::Vector2f( (mid+perspective + tile_w) * screen_w, y), sf::Color::Green);
		line.vertices[9] = sf::Vertex(sf::Vector2f(screen_w, y), sf::Color::Green);


		lines.push_back(line);
		
	}

	for (int i = 0; i < lines.size(); i++)
	{
		window.draw(lines.at(i).vertices,10, sf::Lines);
	}


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