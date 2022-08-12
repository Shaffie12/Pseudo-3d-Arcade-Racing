
#include "SFML/Graphics.hpp"

int screen_w = 1000;
int screen_h = 700;


void DrawPlane(sf::RenderWindow& window, sf::Color col, sf::Vector2f origin, float width, float height)
{
	sf::ConvexShape shape(3);
	shape.setFillColor(col);

	shape.setPointCount(4);
	shape.setPoint(0, sf::Vector2f(0,screen_h));
	shape.setPoint(1, sf::Vector2f(0, screen_h/2));
	shape.setPoint(2, sf::Vector2f(screen_w, screen_h/2));
	shape.setPoint(3, sf::Vector2f(screen_w, screen_h));

	window.draw(shape);
	

}


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
		DrawPlane(w, sf::Color::Green, sf::Vector2f(screen_w/2,screen_h/2),10,10);
		w.display();
			
	}
	

	
	

	return 0;
}