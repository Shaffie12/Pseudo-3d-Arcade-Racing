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
		
		//segment 8 objects
		
		RoadSideTemplate(RoadSideTemplate::ObjectType::Start,180,7,30,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign3,5,0,true,false),

		//segment 7
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign2,6,40,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign3,6,20,true,false),		

		//segment 6
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign2,5,200,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,5,120,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,5,50,true,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,5,50,false,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,5,30,true,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,5,30,false,true),
		
		//segment 5
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,4,170,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,4,170,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,4,120,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,4,120,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign2,4,70,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign3,4,50,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,4,30,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,4,30,true,false),
		
		//segment 3
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign2,3,200,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Rock,3,170,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Rock,3,120,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign3,3,70,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Rock,3,50,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,3,30,false,false),
		
		//segment 2 objects
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,2,200,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,2,200,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,2,180,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,2,180,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,2,120,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,2,120,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,2,100,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,2,100,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,2,80,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,2,80,false,false),
		

		//segment 1 objects
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,160,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,160,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,140,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,140,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,120,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,120,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,100,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,100,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,80,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,1,80,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign2,1,0,true,false),

		//segment 0 objects	
		RoadSideTemplate(RoadSideTemplate::ObjectType::Rock,0,100,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,80,true,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,80,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,0,50,false,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,0,50,true,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,0,30,false,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Sign,0,30,true,true),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,0,false,false),
		RoadSideTemplate(RoadSideTemplate::ObjectType::Tree,0,0,true,false)


	};

	calculateTotalLength();
	

};



