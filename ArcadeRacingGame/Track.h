#ifndef _TRACK_H_
#define _TRACK_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Segment.h"
#include "Util.h"
#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>


class Track :public Drawable
{

public:
	struct Line
	{
		friend class Track;
		sf::Vertex vertices[10];
		sf::Color colours[3];

		float scaledY;
		float perspective;
		float tile_w;
		float middlePt;
		float screenY;
		Line(int y) : middlePt(0.5)
		{

			scaledY = Racing::Util::convertRange(y, 1, GameGlobals::GAME_H / 2, 0, 1);
			perspective = minRoad + scaledY * road_w;
			screenY = y + GameGlobals::GAME_H / 2;
			tile_w = perspective * Track::tile_w;

		}

		
	};
private:
	void updateLines();
	void moveSegment();
	void addSegmentOffset();
	void nextSegment();
	void updateSpeedDistance();

	void lap();

	std::vector<Line>::reverse_iterator rit;
	std::map<std::string, sf::Color> roadColors;
	std::vector<Segment> segments;
	Segment baseSeg;
	int currentSeg = 0;
	float dist; //artificially represents how far player has moved
	float segmentDistance = 0;
	int totalTrackLength;

	

	

public:
	Track(std::map<std::string,sf::Color> colors, std::vector<Segment> segments); 
	virtual void drawElement(sf::RenderTarget& w) override;
	void addPlayerOffset(float amount, bool add);
	void addSpeed(float amount, bool add);
	static float road_w;
	static float tile_w;
	static float minRoad; //minimal amount of road at the highest point on road
	static float segmentAmt;
	static std::vector<Line> lines;
	static Segment* activeSeg;
	static float speed; //artificially represent speed of player
	static float totalDistance;
	static float globalOffset;
	static int laps;


		
	
};




#endif
