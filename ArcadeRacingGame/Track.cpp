#include "Track.h"
#include "Background.h"
#include<iostream>
#include <cmath>

float Track::road_w = 0.9f;
float Track::minRoad = 0.01f;
float Track::trackCurvature = 0;
float Track::speed = 0;
float Track::dist = 0;
float Track::globalOffset = 0;
Track::Segment Track::baseSeg(0, 0);
float Track::segmentAmt = 0;
//i think the colours can be moved to a configuration place later
sf::Color Track::grassLight = sf::Color::Green;
sf::Color Track::grassDark = sf::Color(55, 154, 84);
sf::Color Track::roadLight = sf::Color(178, 195, 183);
sf::Color Track::roadDark = sf::Color(188, 205, 190);
sf::Color Track::tile_col_1 = sf::Color::Red;
sf::Color Track::tile_col_2 = sf::Color::White;


Track::Track() 
{
	
	trackLines = new std::vector<Line>;
	for (int i = 1; i <=GameGlobals::GAME_H/2 ; i++)
	{
	
		Line* line = new Line(i);

		trackLines->push_back(*line);

	}
	

	trackData.push_back(Segment(-0.002,70)); 
	trackData.push_back(Segment(0.002, 1000)); 
	trackData.push_back(Segment(0.0015, 1500));
	trackData.push_back(Segment(0, 2000));
	
	
}

void Track::drawElement(sf::RenderTarget& w)
{

	speed = Racing::Util::clamp(speed, 0, 1);
	dist += speed*1.5;
	
	moveSegment();

	update();

	for (Line& l : *trackLines)
	{
		w.draw(l.vertices, 10, sf::Lines);
	}
		
	//debug
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(0,trackData.at(currentSect).position),sf::Color::White),
		sf::Vertex(sf::Vector2f(GameGlobals::GAME_W, trackData.at(currentSect).position),sf::Color::White)
	};

	w.draw(line, 2, sf::Lines);

}

void Track::update()
{
	double dx = 0;
	double ddx = 0;
	double current_x = 0.5;
	
	
	float segpos = Racing::Util::convertRange(trackData.at(currentSect).position, GameGlobals::GAME_H/2, GameGlobals::GAME_H, 1, GameGlobals::GAME_H/2);
	float td = trackData.at(currentSect).t_curvature;
	float bd = baseSeg.t_curvature; //another way to alias this?
	

	rit = trackLines->rbegin();
	while(rit!=trackLines->rend())
	{
		
		Line& line = *rit;
		

		line.colours[0] = sinf(30 * pow(1 - line.perspective, 10) + dist * 0.1) > 0.0f ? grassLight : grassDark;
		line.colours[1] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? tile_col_1 : tile_col_2;
		line.colours[2] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? roadLight : roadDark;

		if (line.y < segpos)
			dx = td * ((1 - line.scaledY) *(1 - line.scaledY) / 6) * (((trackLines->at(trackLines->size()-1).scaledY) - line.scaledY) *2.5);
		else
			dx = bd * ((1 - line.scaledY) * (1 - line.scaledY) /6) * (((trackLines->at(trackLines->size() - 1).scaledY ) - line.scaledY) * 2.5);


		ddx += dx;
		current_x += ddx;
		line.middlePt = current_x + globalOffset;


		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, line.screenY), line.colours[0]);
		line.vertices[1] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective - line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[0]);

		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective - line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[1]);
		line.vertices[3] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective) * GameGlobals::GAME_W, line.screenY), line.colours[1]);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective) * GameGlobals::GAME_W, line.screenY), line.colours[2]);
		line.vertices[5] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective) * GameGlobals::GAME_W, line.screenY), roadLight);

		//edge 2
		line.vertices[6] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective) * GameGlobals::GAME_W, line.screenY), line.colours[1]);
		line.vertices[7] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective + line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[1]);

		//grass right
		line.vertices[8] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective + line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[0]);
		line.vertices[9] = sf::Vertex(sf::Vector2f(GameGlobals::GAME_W, line.screenY), line.colours[0]);

		++rit;
	}
	

}

void Track::addPlayerOffset(float amount, bool add)
{
	if (add)
		globalOffset += amount;
	else
		globalOffset -= amount;
}

void Track::addSpeed(float amount, bool add)
{ 
	
	if (add)speed += amount; else speed -= amount; 
}

void Track::addSegmentOffset()
{
	if (trackData.at(currentSect).position >= GameGlobals::GAME_H-80 )
	{
		globalOffset += (trackData.at(currentSect).roadOffset * 3 * speed);
		globalOffset = Racing::Util::clamp(globalOffset, -1.1f, 1.1f);
		segmentAmt = trackData.at(currentSect).t_curvature;
		
	}

}

void Track::nextSegment()
{
	if (trackData.at(currentSect).position >= GameGlobals::GAME_H)
	{
		baseSeg = trackData.at(currentSect);

		int next = (currentSect + 1) % trackData.size();
		if (dist >= trackData.at(next).distanceToReach)
		{

			trackData.at(currentSect).position = GameGlobals::GAME_H / 2;
			currentSect = ++currentSect % trackData.size();
		}


	}
}

void Track::moveSegment()
{
	
	trackData.at(currentSect).position += (0.7 * speed);
	
	

	addSegmentOffset();
	nextSegment();
	

		
}
