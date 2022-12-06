#include "UI.h"



UI::UI() 
{
	if (!textFont.loadFromFile("assets/Fonts/VT323.ttf"))
	{
		std::cout<<"could not load fonts"<<'\n';
		
	}

	lap = 0;
	speed = 0;
	timer = 0;

	speedText.setFont(textFont);
	speedText.setFillColor(sf::Color::White);
	speedText.setPosition(50, 50);
	speedText.setScale(sf::Vector2f(0.5, 0.5));

	lapText.setFont(textFont);
	lapText.setFillColor(sf::Color::White);
	lapText.setPosition(230, 50);
	lapText.setScale(sf::Vector2f(0.5, 0.5));

	timerText.setFont(textFont);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(230,70);
	timerText.setScale(sf::Vector2f(0.5, 0.5));
	
	
	

}

void UI::getRaceTimer(float timer)
{
	this->timer = timer;
}

void UI::getTrackSpeed(float Trackspeed)
{
	speed = Trackspeed;
}

void UI::getCurrentLap(int lapNumber)
{
	lap = lapNumber;
}

void UI::update(float dt)
{
	ss.clear();
	ss << Racing::Util::roundToDP(Track::acceleration, 3) * 100 << ';' << Track::LAP << ';' << timer;
	std::string spd;
	std::string lap;
	std::string time;
	std::getline(ss, spd, ';');
	std::getline(ss, lap, ';');
	ss >> time;


	speedText.setString("speed: " + spd + "km/h");
	lapText.setString("LAP: " + lap);
	timerText.setString("TIME: "+time);
}

void UI::drawElement(sf::RenderTarget& w)
{
	
	w.draw(speedText);
	w.draw(lapText);
	w.draw(timerText);

}
