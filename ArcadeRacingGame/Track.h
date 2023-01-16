#ifndef _TRACK_H_
#define _TRACK_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Segment.h"
#include "Util.h"
#include "SoundManager.h"
#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>


class Track :public Drawable
{

	friend class RoadObject;
	friend class Background;
	friend class UI;
	friend class Racer;
	friend class Line;
public:
	struct Line
	{
		
		sf::Vertex vertices[10];
		sf::Color colours[3];

		float scaledY;
		float perspective;
		float tile_w;
		float middlePt;
		float screenY;
		Line(int y, Track& t) : middlePt(0.5)
		{

			scaledY = Racing::Util::convertRange(y, 1, GameGlobals::GAME_H / 2, 0, 1);
			perspective = t.minRoad + scaledY * t.road_w;
			screenY = y + GameGlobals::GAME_H / 2;
			tile_w = perspective * t.tile_w;

		}


	};
private:

	void moveSegment(float deltaTime);
	void addSegmentOffset();
	void nextSegment();

	std::vector<Line>::reverse_iterator rit;
	std::map<std::string, sf::Color> roadColors;
	std::vector<Segment> segments;

	int currentSeg = 0;
	int progressAroundTrack;
	int totalTrackLength;
	float distanceToSegmentEnd;

	
	std::vector<Line> lines;
	Segment* activeSeg = nullptr;
	Segment* baseSeg = nullptr;
	float acceleration = 0;
	float dist = 0;
	float trackOffset = 0;

public:
	Track(std::map<std::string, sf::Color> colors, std::vector<Segment> segments, int totalTrackDistance);
	~Track();
	void update(const float& deltaTime) override;
	void updateTrackLines();
	virtual void drawElement(sf::RenderTarget& w) override;
	void addPlayerOffset(float amount, bool add);
	void addAcceleration(float amount);
	static const float road_w;
	static const float tile_w;
	static const float minRoad;
	
	static int lapsDone;





};
#endif