#include "Track.h"
#include<iostream>
#include <cmath>

float Track::road_w = 0.6f;
float Track::minRoad = 0.01f;
float Track::trackCurvature = 0;
//i think the colours can be moved to a configuration place later
sf::Color Track::grassLight = sf::Color::Green;
sf::Color Track::grassDark = sf::Color(55, 154, 84);
sf::Color Track::roadLight = sf::Color(178, 195, 183);
sf::Color Track::roadDark = sf::Color(188, 205, 190);
sf::Color Track::tile_col_1 = sf::Color::Red;
sf::Color Track::tile_col_2 = sf::Color::White;


Track::Track(): baseSeg(Segment(0,0))
{
	
	trackLines = new std::vector<Line>;
	for (int i = 0; i < GameGlobals::SCREEN_H/2 ; i++)
	{
		Line* line = new Line((GameGlobals::SCREEN_H/2)+i);
		trackLines->push_back(*line);
	}

	trackData.push_back(Segment(0.0000133, 30));
	trackData.push_back(Segment(-0.0000133, 100));
	
}

void Track::drawElement(sf::RenderWindow& w)
{

	speed = Racing::Util::clamp(speed, 0, 1);
	dist += speed;


	moveSegment();
	drawTrackLines();

	
	//draw the lines on screen
	
	

	for (Line& l : *trackLines)
	{
		w.draw(l.vertices, 10, sf::Lines);
	}
		

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(0,trackData.at(currentSect).position),sf::Color::White),
		sf::Vertex(sf::Vector2f(GameGlobals::SCREEN_W, trackData.at(currentSect).position),sf::Color::White)
	};

	w.draw(line, 2, sf::Lines);

}

void Track::drawTrackLines()
{
	double dx = 0;
	double ddx = 0;
	double current_x = 0.5;
	
	rit = trackLines->rbegin();
	while(rit!=trackLines->rend())
	{
		
		Line& line = *rit;
		
	
		//line.perspective = minRoad + line.scaledY * road_w;
		line.colours[0] = sinf(30 * pow(1 - line.perspective, 10) + dist * 0.1) > 0.0f ? grassLight : grassDark;
		line.colours[1] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? tile_col_1 : tile_col_2;
		line.colours[2] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? roadLight : roadDark;

		
		if (line.y < trackData.at(currentSect).position)
			dx = trackData.at(currentSect).t_curvature;
		else
			dx=baseSeg.t_curvature;
		

		ddx += 1.5 * (1-line.scaledY/2) * dx; //still a  bug where we can move the road but not the curve
		current_x += ddx;
		line.middlePt = current_x;
	
			
		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, line.y), line.colours[0]);
		line.vertices[1] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective - line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[0]);

		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective - line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[1]);
		line.vertices[3] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective) * GameGlobals::SCREEN_W, line.y), line.colours[1]);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective) * GameGlobals::SCREEN_W, line.y), line.colours[2]);
		line.vertices[5] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective) * GameGlobals::SCREEN_W, line.y), roadLight);

		//edge 2
		line.vertices[6] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective) * GameGlobals::SCREEN_W, line.y), line.colours[1]);
		line.vertices[7] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective + line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[1]);

		//grass right
		line.vertices[8] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective + line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[0]);
		line.vertices[9] = sf::Vertex(sf::Vector2f(GameGlobals::SCREEN_W, line.y), line.colours[0]);

		++rit;
	}
	



}


void Track::offsetCenter(float amount, bool add)
{
	if (add)
		middlePt += amount;
	else
		middlePt -= amount;
}

void Track::addSpeed(float amount, bool add)
{ 
	
	if (add)speed += amount; else speed -= amount; 
}
float Track::getDist() { return dist; }

void Track::moveSegment()
{
	
	trackData.at(currentSect).position += 2*speed;

	if (trackData.at(currentSect).position >= GameGlobals::SCREEN_H)
	{
		
		trackData.at(currentSect).position = GameGlobals::SCREEN_H / 2;
		baseSeg = trackData.at(currentSect);
		currentSect = ++currentSect % trackData.size(); //we should only move to the next segment if the distance has been reached?
		
	}
		

	
	
		
}

void Track::adjustRoadSpeed(float playerPosition)
{
	if (fabs(playerPosition - trackCurvature) > 0.48)
	{
		//speed =0.02;
		
	}
	
		
}