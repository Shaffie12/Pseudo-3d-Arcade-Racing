#include "Track.h"
#include<iostream>
#include <cmath>

float Track::road_w = 0.9f;
float Track::tile_w = 0.15;
float Track::minRoad = 0.01;
//these shouldnt be static.
float Track::dist = 0;
float Track::trackOffset = 0;
float Track::acceleration = 0; 
std::vector<Track::Line> Track::lines = std::vector<Track::Line>(); 
Segment* Track::activeSeg = nullptr;

Track::Track(std::map<std::string,sf::Color> colors, std::vector<Segment> segments, int totalTrackLen):baseSeg ( Segment(-1,0, 0))
{	
	acceleration = 0;
	dist = 0;
	trackOffset = 0;
	activeSeg = nullptr;
	lines = std::vector<Track::Line>();
	for (int i = 1; i <=GameGlobals::GAME_H/2 ; i++)
		lines.push_back(Line(i));
	this->segments = segments;
	roadColors = colors;
	activeSeg = &this->segments.at(0);
	distanceToSegmentEnd = activeSeg->length;
	totalTrackLength = totalTrackLen;
	lapsDone = 0;
	
	
}

void Track::update(float deltaTime)
{
	acceleration = Racing::Util::clamp(acceleration, 0, 1); //could move these
	dist += acceleration * 100* deltaTime;

	moveSegment(deltaTime);
	updateTrackLines();

}

void Track::updateTrackLines()
{
	double dx = 0;
	double ddx = 0;
	double current_x = 0.5;

	float td = activeSeg->curvature;
	float bd = baseSeg.curvature;

	rit = lines.rbegin();
	while (rit != lines.rend())
	{

		Line& line = *rit;


		line.colours[0] = sinf(30 * pow(1 - line.perspective, 10) + dist * 0.1) > 0.0f ? roadColors.find("grassLight")->second : roadColors.find("grassDark")->second;
		line.colours[1] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? roadColors.find("rumble1")->second : roadColors.find("rumble2")->second;
		line.colours[2] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? roadColors.find("roadLight")->second : roadColors.find("roadDark")->second;

		if (line.screenY < activeSeg->screen_y)
			dx = td * ((1 - line.scaledY) * (1 - line.scaledY) / 6) * (((lines.at(lines.size() - 1).scaledY) - line.scaledY) * 2.5);
		else
			dx = bd * ((1 - line.scaledY) * (1 - line.scaledY) / 6) * (((lines.at(lines.size() - 1).scaledY) - line.scaledY) * 2.5);


		ddx += dx;
		current_x += ddx;
		line.middlePt = current_x + trackOffset;


		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, line.screenY), line.colours[0]);
		line.vertices[1] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective - line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[0]);

		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective - line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[1]);
		line.vertices[3] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective) * GameGlobals::GAME_W, line.screenY), line.colours[1]);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f((line.middlePt - line.perspective) * GameGlobals::GAME_W, line.screenY), line.colours[2]);
		line.vertices[5] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective) * GameGlobals::GAME_W, line.screenY), line.colours[2]);//was roadLight

		//edge 2
		line.vertices[6] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective) * GameGlobals::GAME_W, line.screenY), line.colours[1]);
		line.vertices[7] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective + line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[1]);

		//grass right
		line.vertices[8] = sf::Vertex(sf::Vector2f((line.middlePt + line.perspective + line.tile_w) * GameGlobals::GAME_W, line.screenY), line.colours[0]);
		line.vertices[9] = sf::Vertex(sf::Vector2f(GameGlobals::GAME_W, line.screenY), line.colours[0]);

		++rit;
	}
}

void Track::drawElement(sf::RenderTarget& w)
{

	for (Line& l :lines)
	{
		w.draw(l.vertices, 10, sf::Lines);
	}
		
	
	//debug
	/*
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(0,activeSeg->screen_y),sf::Color::White),
		sf::Vertex(sf::Vector2f(GameGlobals::GAME_W, activeSeg->screen_y),sf::Color::White)
	};
	

	w.draw(line, 2, sf::Lines);
	*/

}


void Track::addPlayerOffset(float amount, bool add) //change
{
	if (add)
		trackOffset += amount;
	else
		trackOffset -= amount;
}

void Track::addAcceleration(float amount){ acceleration += amount;}

void Track::addSegmentOffset()
{
	if (activeSeg->screen_y >= GameGlobals::GAME_H-80 )
	{
		trackOffset += (activeSeg->curvature * 8 * acceleration); 
		trackOffset = Racing::Util::clamp(trackOffset, -1.1f, 1.1f);
		
	}

}

void Track::nextSegment()
{

	if (activeSeg->screen_y>= GameGlobals::GAME_H)
	{
	
		baseSeg = *activeSeg; 
		if (distanceToSegmentEnd <= 0)
		{
			
			activeSeg->screen_y = GameGlobals::GAME_H / 2;
			progressAroundTrack += activeSeg->length;
			if (progressAroundTrack == totalTrackLength)
			{
				lapsDone++;
				progressAroundTrack = 0;
			}
			
			currentSeg = ++currentSeg % segments.size();
			distanceToSegmentEnd = segments.at(currentSeg).length;
			activeSeg = &segments.at(currentSeg);
		}
	
	}
	
}

void Track::moveSegment(float deltaTime)
{
	activeSeg->screen_y += (1 *acceleration);
	distanceToSegmentEnd -= acceleration * 100 * deltaTime;
	addSegmentOffset();
	nextSegment();
}


