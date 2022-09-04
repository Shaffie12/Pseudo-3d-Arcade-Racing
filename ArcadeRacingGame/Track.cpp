#include "Track.h"
#include<iostream>
#include <cmath>

float Track::road_w = 0.65f;
float Track::minRoad = 0.01f;
float Track::trackCurvature = 0;
//i think the colours can be moved to a configuration place later
sf::Color Track::grassLight = sf::Color::Green;
sf::Color Track::grassDark = sf::Color(55, 154, 84);
sf::Color Track::roadLight = sf::Color(178, 195, 183);
sf::Color Track::roadDark = sf::Color(188, 205, 190);
sf::Color Track::tile_col_1 = sf::Color::Red;
sf::Color Track::tile_col_2 = sf::Color::White;


Track::Track(): baseSeg(Segment(0.5,0))
{
	
	trackLines = new std::vector<Line>;
	for (int i = 0; i < GameGlobals::SCREEN_H/2 ; i++)
	{
		Line* line = new Line((GameGlobals::SCREEN_H/2)+i);
		trackLines->push_back(*line);
	}

	trackData.push_back(Segment(0.1, 30));
	trackData.push_back(Segment(1, 60)); 
	//curve shouldnt be going off screen
	//comment

	
}

void Track::drawElement(sf::RenderWindow& w)
{
	
	speed = Racing::Util::clamp(speed, 0, 1);
	dist += speed;
	
	//baseDiff = Racing::Util::roundToDP((baseSeg.t_curvature - trackLines->at((GameGlobals::SCREEN_H / 2) - 1).middlePt),3);
	//offset = baseDiff * 0.01 * speed;
	

	if (dist > trackData.at(currentSect).distanceToReach)
	{
		
		offsetDiff = Racing::Util::roundToDP((trackData.at(currentSect).t_curvature - trackLines->at(0).middlePt),3);
		
		if (abs(offsetDiff)>0)
			curveDirection = offsetDiff > 0 ? 1 : -1;
		
		if (abs(offsetDiff) >0.01) 
		{
			moveAmount = curveDirection * 0.004 * speed;
			curvature += moveAmount;
			trackCurvature = curvature;
		}
		else
			moveAmount = 0;

		moveSegment();
	

	}
	else
		moveAmount = 0;
	

	drawTrackLines();
		
	//draw the lines on screen
	for (Line& l: *trackLines)
		w.draw(l.vertices, 10, sf::Lines);

}

void Track::drawTrackLines()
{
	for (Line& line: *trackLines)
	{
		line.perspective = minRoad + line.scaledY * road_w; // change perspective based on the players position 
		//tweak multiplier on dist to change "speed look"
		line.colours[0] = sinf(15 * pow(1 - line.perspective, 10) + dist * 0.1) > 0.0f ? grassLight : grassDark;
		line.colours[1] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? tile_col_1 : tile_col_2;
		line.colours[2] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.8) > 0.0f ? roadLight : roadDark;

		
		line.middlePt += moveAmount * powf(1 - line.perspective, 10); 
			
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
	trackData.at(currentSect).position += 1 * speed;
	
	if (trackData.at(currentSect).position >= GameGlobals::SCREEN_H && abs(offsetDiff)<0.01 )
	{
		
		baseSeg = trackData.at(currentSect);
	
		trackData.at(currentSect).position = GameGlobals::SCREEN_H / 2;
		currentSect = (++currentSect) % trackData.size(); //we can replace this system with 2 references and pointers

	}
	
		
	//move the segment by n lines a frame
	//once the segment hits the bottom of the screen, the entire road should be shifted to the same direction as the curve.
	//its also possible to draw the road thinner the further away from the centre it is (within a reasonable amount)
	
	//i changed the data to a list of segments for now.
		
}

void Track::adjustRoadSpeed(float playerPosition)
{
	if (fabs(playerPosition - trackCurvature) > 0.48)
	{
		//speed =0.02;
		
	}
	
		
}