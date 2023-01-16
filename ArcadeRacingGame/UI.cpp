#include "UI.h"

UI::UI(Track& t) : track(t)
{

	speed = 0;
	timer = 0;

	speedText.setFont(FontsManager::GetInstance()->font_basic);
	speedText.setFillColor(sf::Color::White);
	speedText.setPosition(50, 50);
	speedText.setScale(sf::Vector2f(0.5, 0.5));

	lapText.setFont(FontsManager::GetInstance()->font_basic);
	lapText.setFillColor(sf::Color::White);
	lapText.setPosition(230, 50);
	lapText.setScale(sf::Vector2f(0.5, 0.5));

	timerText.setFont(FontsManager::GetInstance()->font_basic);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(230,70);
	timerText.setScale(sf::Vector2f(0.5, 0.5));
	
	
	

}

void UI::getRaceTimer(float timer)
{
	this->timer = timer;
}

void UI::update(const float& dt)
{
	ss.clear();
	ss << Racing::Util::roundToDP(track.acceleration, 3) * 100 << ';' << Track::lapsDone << ';' << timer;
	std::string spd;
	std::string lap_string;
	std::string time;
	std::getline(ss, spd, ';');
	std::getline(ss, lap_string, ';');
	ss >> time;


	speedText.setString("speed: " + spd + "km/h");
	lapText.setString("LAP: " + lap_string);
	timerText.setString("TIME: "+time);
}

void UI::drawElement(sf::RenderTarget& w)
{
	
	w.draw(speedText);
	w.draw(lapText);
	w.draw(timerText);

}
