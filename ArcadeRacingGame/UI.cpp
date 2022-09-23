#include "UI.h"



UI::UI() 
{
	if (!textFont.loadFromFile("assets/Fonts/VT323.ttf"))
	{
		std::cout<<"could not load fonts"<<'\n';
		
	}

	playerSpeed.setFont(textFont);
	playerSpeed.setFillColor(sf::Color::White);
	playerSpeed.setPosition(50, 50);
	playerSpeed.setScale(sf::Vector2f(0.5, 0.5));

	distanceTravelled.setFont(textFont);
	distanceTravelled.setFillColor(sf::Color::White);
	distanceTravelled.setPosition(50, 65);
	distanceTravelled.setScale(sf::Vector2f(0.5, 0.5));
	
	

}

void UI::drawElement(sf::RenderTarget& w)
{
	std::stringstream ss; //is there a way to only declare this once?
	ss << Racing::Util::roundToDP(Track::speed, 3) * 100 << ';' << Track::dist;		 //these cars can go up to 360km/ph
	std::string spd;
	std::string dst;
	std::getline(ss, spd, ';');
	ss >> dst;


	playerSpeed.setString("Speed: " + spd+ "km/h");
	distanceTravelled.setString("Distance: " + dst);
	w.draw(playerSpeed);
	w.draw(distanceTravelled);

}
