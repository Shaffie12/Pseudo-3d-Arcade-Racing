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
		Segment(0,0,300),
		Segment(1,0.003f,350),
		Segment(2,0.001f, 600),
		Segment(3,-0.0033f,500),
		Segment(4,0.0015f,50),
		Segment(5,0,150),
		Segment(6,0.002f,100),
		Segment(7,0,70)	
		
	};
	objects =
	{
		//segment 0 objects
		RoadSideTemplate(RoadSideTemplate::ObjectType::Rock,0,100,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,80,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,80,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,60,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,60,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,30,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,30,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,0,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,0,true),

		RoadSideTemplate(RoadSideTemplate::ObjectType::Start,180,7,30,false)
		/*
		new Tree(0,80,true),
		new Tree(0,80,false),
		new Tree(0,60,false),
		new Tree(0,60,true),
		new Tree(0,30,false),
		new Tree(0,30,true),
		new Tree(0,0,true),
		new Tree(0,0,false),

		//segment 1



		//segment 7
		new StartSign(180, 7, 30,false)
		*/
	
		
	};

	calculateTotalLength();
	

};



