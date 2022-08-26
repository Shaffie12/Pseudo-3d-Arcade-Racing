#include "Track.h"
#include<iostream>
#include <cmath>

float Track::road_w = 0.8f;
float Track::minRoad = 0.01f;
float Track::percentOfPersp = 0.5f;
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
		
	trackData.push_back(std::make_pair(1, 30)); //curve of 0.2 appearing at 30 units in
	trackData.push_back(std::make_pair(0.5, 100));
	trackData.push_back(std::make_pair(0, 300));
	
}

void Track::drawElement(sf::RenderWindow& w)
{
	//before we start drawing, check if any curve has been reached
	//optimise later
	if (dist > trackData.at(currentSect).second)
		if (curvature == 0 &&  !activeSegment)
		{
			moveAmount = abs((trackData.at(currentSect).first - middlePt)); //how much to move 
			curvature = (trackData.at(currentSect).first - middlePt) / abs((trackData.at(currentSect).first - middlePt)); //normalise for direction
			activeSegment = true;
		}
			
		else
		{
			if (moveAmount> 0)
			{
				
				middlePt += curvature * (0.5f * GameGlobals::elapsedTime);
				moveAmount -= 0.5f * GameGlobals::elapsedTime;
			}
				
				
			else
			{
				curvature = 0;
				moveAmount = 0;
				currentSect = (++currentSect) % trackData.size();
				activeSegment = false;
			}
				
			
		}
			
	
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

		line.colours[0] = sinf(15 * pow(1 - line.perspective, 10) + dist * 0.1) > 0.0f ? grassLight : grassDark;
		line.colours[1] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.7) > 0.0f ? tile_col_1 : tile_col_2;
		line.colours[2] = sinf(50 * pow(1 - line.perspective, 5) + dist * 0.7) > 0.0f ? roadLight : roadDark;
	
		 
		//float percentOfSeg = 1 - ((line.y - (GameGlobals::SCREEN_H / 2)) / (segPosition - (GameGlobals::SCREEN_H / 2)));
												//was 0.5f before
		//line.middlePt = line.y < segPosition ? line.middlePt + (curvature * percentOfSeg) * pow((1 - line.perspective), 3) : line.middlePt;
		
		//problem when segment hits bottom the end of the road is not being offset
		
		//draw the vertices for the lines
		
		middlePt = 0.5f + moveAmount * powf( (1 - line.perspective), 3);
		//grass left
		line.vertices[0] = sf::Vertex(sf::Vector2f(0, line.y), line.colours[0]);
		line.vertices[1] = sf::Vertex(sf::Vector2f((middlePt - line.perspective - line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[0]);

		//road edge l
		line.vertices[2] = sf::Vertex(sf::Vector2f((middlePt - line.perspective - line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[1]);
		line.vertices[3] = sf::Vertex(sf::Vector2f((middlePt - line.perspective) * GameGlobals::SCREEN_W, line.y), line.colours[1]);

		//road 
		line.vertices[4] = sf::Vertex(sf::Vector2f((middlePt - line.perspective) * GameGlobals::SCREEN_W, line.y), line.colours[2]);
		line.vertices[5] = sf::Vertex(sf::Vector2f((middlePt + line.perspective) * GameGlobals::SCREEN_W, line.y), roadLight);

		//edge 2
		line.vertices[6] = sf::Vertex(sf::Vector2f((middlePt + line.perspective) * GameGlobals::SCREEN_W, line.y), line.colours[1]);
		line.vertices[7] = sf::Vertex(sf::Vector2f((middlePt + line.perspective + line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[1]);

		//grass right
		line.vertices[8] = sf::Vertex(sf::Vector2f((middlePt + line.perspective + line.tile_w) * GameGlobals::SCREEN_W, line.y), line.colours[0]);
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

void Track::addDist(float amount) { dist += amount; }
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