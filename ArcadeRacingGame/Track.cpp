#include "Track.h"
#include<iostream>

sf::Color Track::grassLight = sf::Color::Green;
sf::Color Track::grassDark = sf::Color(55, 154, 84);
sf::Color Track::roadLight = sf::Color(178, 195, 183);
sf::Color Track::roadDark = sf::Color(188, 205, 190);
sf::Color Track::tile_col_1 = sf::Color::Red;
sf::Color Track::tile_col_2 = sf::Color::White;


Track::Track()
{
	trackData.push_back(std::make_pair(0, 20));
	trackData.push_back(std::make_pair(0.2f, 100));
}

void Track::drawElement(sf::RenderWindow& w)
{
	
	std::vector<Line> lines;
	float y;
	float percentOfSeg;

	//construct the lines
	for (int i = 0; i < GameGlobals::SCREEN_H / 2; i++)
	{
		
		y = (GameGlobals::SCREEN_H / 2) + i; //middle of screen downward
		float scaledY= ((y - (GameGlobals::SCREEN_H / 2)) / (GameGlobals::SCREEN_H - (GameGlobals::SCREEN_H / 2))); //scaling the 300-600 values to values between 0-1
		float perspective = minRoad + scaledY * percentOfPersp; //calculate perspective
		tile_w = perspective * 0.2; //adjust tile width

		getNextCurvature();

		//to view curves more accurately, calculate how far offset the line should be with regards to the curved segment which is moving down the screen
		percentOfSeg = 1 - ((y - (GameGlobals::SCREEN_H / 2)) / (segPosition - (GameGlobals::SCREEN_H / 2))); 
		mid = y < segPosition ? 0.5 + (percentOfSeg * curvature) * pow((1 - perspective), 3) : baseSegOffset;


		//calculate the line and to list
		lines.push_back(drawTrackLine(y,mid,perspective));

		//need to lerp first the offset, and then the segment down.  also the input is being ovewritten so isnt working 

	}

	//draw the lines on screen
	for (int i = 0; i < lines.size(); i++)
		w.draw(lines.at(i).vertices, 10, sf::Lines);

}

Track::Line Track::drawTrackLine(int y, float middlePt, float persp)
{
	Line line(persp, dist);


	//draw the vertices for the lines

	//grass left
	line.vertices[0] = sf::Vertex(sf::Vector2f(0, y), line.colours[0]);
	line.vertices[1] = sf::Vertex(sf::Vector2f((mid - persp - tile_w) * GameGlobals::SCREEN_W, y), line.colours[0]);

	//road edge l
	line.vertices[2] = sf::Vertex(sf::Vector2f((mid - persp - tile_w) * GameGlobals::SCREEN_W, y), line.colours[1]);
	line.vertices[3] = sf::Vertex(sf::Vector2f((mid - persp) * GameGlobals::SCREEN_W, y), line.colours[1]);

	//road 
	line.vertices[4] = sf::Vertex(sf::Vector2f((mid - persp) * GameGlobals::SCREEN_W, y), line.colours[2]);
	line.vertices[5] = sf::Vertex(sf::Vector2f((mid + persp) * GameGlobals::SCREEN_W, y), roadLight);

	//edge 2
	line.vertices[6] = sf::Vertex(sf::Vector2f((mid + persp) * GameGlobals::SCREEN_W, y), line.colours[1]);
	line.vertices[7] = sf::Vertex(sf::Vector2f((mid + persp + tile_w) * GameGlobals::SCREEN_W, y), line.colours[1]);

	//grass right
	line.vertices[8] = sf::Vertex(sf::Vector2f((mid + persp + tile_w) * GameGlobals::SCREEN_W, y), line.colours[0]);
	line.vertices[9] = sf::Vertex(sf::Vector2f(GameGlobals::SCREEN_W, y), line.colours[0]);

	return line;
}


void Track::offsetCenter(float amount, bool add)
{
	if (add)
		mid += amount;
	else
		mid -= amount;
}

void Track::addDist(float amount) { dist += amount; }
float Track::getDist() { return dist; }
void Track::getNextCurvature()
{

	if (dist >= trackData.at(currentSect).second)
	{
		currentSect = ++currentSect % trackData.size();
		if (currentSect == 0)
			dist = 0;
	}
		
	curvature = trackData.at(currentSect).first;
	//moveSegment();
}

void Track::moveSegment()
{
	segPosition += 2; //*delta time?
	if (segPosition == GameGlobals::SCREEN_H)
	{
		baseSegOffset = curvature;
		segPosition = GameGlobals::SCREEN_H / 2;
	}
		
}