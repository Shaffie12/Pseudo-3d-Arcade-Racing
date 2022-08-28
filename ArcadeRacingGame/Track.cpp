#include "Track.h"
#include<iostream>
#include <cmath>

float Track::road_w = 0.8f;
float Track::minRoad = 0.01f;
float Track::percentOfPersp = 0.8f;
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
	for (int i = 0; i < GameGlobals::SCREEN_H / 2; i++)
	{
		Line* line = new Line((GameGlobals::SCREEN_H/2)+i);
		trackLines->push_back(*line);
	}
		
	trackData.push_back(std::make_pair(1, 30)); 
	trackData.push_back(std::make_pair(0, 700));
	trackData.push_back(std::make_pair(0.5, 1000));
	
}

void Track::drawElement(sf::RenderWindow& w)
{
	
	speed = Racing::Util::clamp(speed, 0, 1);
	dist += speed;
	

	if (dist > trackData.at(currentSect).second)
	{
		int scaled_diff = (trackData.at(currentSect).first - curvature) * 100; //this can be global

		if (abs(scaled_diff) <= 1)
			currentSect = (++currentSect) % trackData.size();
		else
		{
			moveAmount = (scaled_diff/abs(scaled_diff)) * 0.01 * speed;
				//((static_cast<float> (scaled_diff) / 100.0f) * 0.02) *speed;
			curvature += moveAmount;

		}

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

		line.tile_w = line.perspective * 0.2; //adjust tile width

		//tweak multiplier on dist to change "speed look"
		line.colours[0] = sinf(15 * pow(1 - line.perspective, 10) + dist * 0.3) > 0.0f ? grassLight : grassDark;
		line.colours[1] = sinf(50 * pow(1 - line.perspective, 5) + dist * 1.5) > 0.0f ? tile_col_1 : tile_col_2;
		line.colours[2] = sinf(50 * pow(1 - line.perspective, 5) + dist * 1.5) > 0.0f ? roadLight : roadDark;

		//adjust lines
		//buggy - line is not getting moveAmount as zero
		line.middlePt += moveAmount *powf((1 - line.perspective), 10);
		
		
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

void Track::getNextCurvature()
{
	
	if (dist >= trackData.at(currentSect).second)
	{
		
		//float diff = 0.2f- curvature;
		//curvature += diff * (GameGlobals::elapsedTime);
		//currentSect++;
		//moveSegment();
	}
	
		
}

void Track::moveSegment()
{
	//segPosition +=50* GameGlobals::elapsedTime;
	if (segPosition >= GameGlobals::SCREEN_H)
	{
		
		//baseSegOffset = curvature; //didnt take the y into account here
		//segPosition = GameGlobals::SCREEN_H / 2;
		//currentSect = (++currentSect) % trackData.size();
		
		//the problem is we are sending the segment back up and then its evaluating that all the lines are below the segment, setting their x coord back to an incorrect value
	}
		
}

/*
	//cant do this here it causes weirdness, impossible to debug.  Try to make it move left and right smoothly through the track segments
		if (dist > trackData.at(currentSect).second )
		{
			float moveBy = (trackData.at(currentSect).first - line.pos_before_move) * GameGlobals::elapsedTime;
			float diff = trackData.at(currentSect).first - line.middlePt;
			if (abs(diff)>0.01f)
			{

				std::cout << "line " << line.y << " was moved by: " << moveBy  << '\n';
				line.middlePt += moveBy;
			}
			else
			{
				currentSect++;
				std::cout << "moved sectors" << '\n';
				line.pos_before_move = line.middlePt;
			}


		}
		*/