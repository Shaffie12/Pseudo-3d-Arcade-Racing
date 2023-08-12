#ifndef UI_H_
#define UI_H_
#include "Drawable.h"
#include "FontsManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Track.h"
#include <string>

class UI : public Drawable
{
	public:
		UI(Track& t);
		void drawElement(sf::RenderTarget& w);
		void update(const float& dt) override;
		void getRaceTimer(float timer);
		
	private:
		Track& track;
		std::stringstream ss;
		sf::Text speedText;
		sf::Text lapText;
		sf::Text timerText;

		float speed;
		int timer;

};


#endif 
