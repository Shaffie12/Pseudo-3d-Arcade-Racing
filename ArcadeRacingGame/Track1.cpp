#include "Track1.h"

Track1::Track1() :TrackData() 
{
	//use a map instead
	colors = {
		std::make_pair(sf::Color::Green,"grassLight"),
		std::make_pair(sf::Color(55, 154, 84), "grassDark"),
		std::make_pair(sf::Color(178, 195, 183), "roadLight"),
		std::make_pair(sf::Color(188, 205, 190),"roadDark"),
		std::make_pair(sf::Color::Red,"rumble1"),
		std::make_pair(sf::Color::White, "rumble2")
	};
	segments =
	{
		
	};

};

