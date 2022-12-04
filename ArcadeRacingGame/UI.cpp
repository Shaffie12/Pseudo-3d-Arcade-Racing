#include "UI.h"



UI::UI() 
{
	if (!textFont.loadFromFile("assets/Fonts/VT323.ttf"))
	{
		std::cout<<"could not load fonts"<<'\n';
		
	}

	playeraccelerationText.setFont(textFont);
	playeraccelerationText.setFillColor(sf::Color::White);
	playeraccelerationText.setPosition(50, 50);
	playeraccelerationText.setScale(sf::Vector2f(0.5, 0.5));

	lapText.setFont(textFont);
	lapText.setFillColor(sf::Color::White);
	lapText.setPosition(230, 50);
	lapText.setScale(sf::Vector2f(0.5, 0.5));
	
	
	

}

void UI::drawElement(sf::RenderTarget& w)
{
	std::stringstream ss; //is there a way to only declare this once?
	ss << Racing::Util::roundToDP(Track::acceleration, 3) * 100 << ';' << Track::LAP;	 //these cars can go up to 360km/ph
	std::string spd;
	std::string lap;
	std::getline(ss, spd, ';');
	ss >> lap;


	playeraccelerationText.setString("acceleration: " + spd+ "km/h");
	lapText.setString("LAP: " + lap);
	w.draw(playeraccelerationText);
	w.draw(lapText);

}
