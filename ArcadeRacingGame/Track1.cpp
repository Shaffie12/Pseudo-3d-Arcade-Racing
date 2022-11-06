#include "Track1.h"

Track1::Track1() :TrackData() 
{
	
	colors = {
		std::make_pair("grassLight",sf::Color::Green),
		std::make_pair("grassDark",sf::Color(55, 154, 84)),
		std::make_pair("roadLight",sf::Color(178, 195, 183)),
		std::make_pair("roadDark",sf::Color(188, 205, 190)),
		std::make_pair("rumble1",sf::Color::Red),
		std::make_pair("rumble2",sf::Color::White)
	};
	segments =
	{
		Segment(0,0,0),
		Segment(1,-0.002f,10),
		Segment(2,0.0015,230),
		Segment(3,0, 80)
		//define track here
		
		
	};
	objects = //i wanted to have a struture that couples the segments and the road objects but caused circular ref issues.
	{
		
		Sign(0,130,true),
		Rock(0,100,true),
		Tree(0,30,false),
		Tree(0,30,false),
		Tree(0,0,true),
		Tree(0,0,true),
		

		
	};
	

};



