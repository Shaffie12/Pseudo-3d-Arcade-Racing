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

	laps.setFont(textFont);
	laps.setFillColor(sf::Color::White);
	laps.setPosition(50, 80);
	laps.setScale(sf::Vector2f(0.5f, 0.5f));

	
	
	

}

void UI::drawElement(sf::RenderTarget& w)
{
	std::stringstream ss; //is there a way to only declare this once?
	ss << Racing::Util::roundToDP(Track::speed, 3) * 100 << ';' << Track::totalDistance << ';' << Track::laps;	 //these cars can go up to 360km/ph
	std::string spd, dst, l;
	std::getline(ss, spd, ';');
	std::getline(ss, dst, ';');
	ss >> l;


	playerSpeed.setString("Speed: " + spd+ "km/h");
	distanceTravelled.setString("Distance: " + dst);
	laps.setString("Lap: " + l);
	w.draw(playerSpeed);
	w.draw(distanceTravelled);
	w.draw(laps);

}
