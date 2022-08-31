#ifndef TRACK_H_
#define TRACK_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Util.h"
#include <SFML/Graphics.hpp>
#include<vector>

class Track :public Drawable
{
	
	public:
		Track();
		void drawElement(sf::RenderWindow& w);
		void offsetCenter(float amount, bool add);
		void addSpeed(float amount, bool add);
		float getDist();
		void adjustRoadSpeed(float playerPosition);
		static float trackCurvature;


	
	private:
		struct Line 
		{ 
			sf::Vertex vertices[10]; 
			sf::Color colours[3];
			int y; //i dont think it needs this since its always passed it
			float scaledY;
			float perspective;
			float tile_w;
			float middlePt;
			Line(int yval) : y(yval), middlePt(0.5)
			{
				scaledY = ((y - (GameGlobals::SCREEN_H / 2)) / (GameGlobals::SCREEN_H - (GameGlobals::SCREEN_H / 2))) ;
				perspective = minRoad +scaledY *road_w;
				//i think the colours need to be redrawn every frame too
				tile_w = perspective * 0.15;
				
			}
		};

		struct Segment
		{
			float t_curvature;
			float distanceToReach;
			float position;
			Segment(float curvature, float distance) : position(GameGlobals::SCREEN_H / 2) { t_curvature = curvature; distanceToReach = distance; }
			Segment(const Segment& s) { this->distanceToReach = s.distanceToReach; this->position = GameGlobals::SCREEN_H / 2; this->t_curvature = s.t_curvature; }
		};

		void drawTrackLines();
		void moveSegment();
		
		
		static float road_w;
		static float minRoad; //minimal amount of road at the highest point on road
		float middlePt = 0.5;
		float speed = 0; //artificially represent speed of player
		float dist = 0; //artificially represents how far player has moved
		std::vector<Line>* trackLines;

		int curveDirection = 0;
		int scaled_diff = 0;
		float baseDiff = 0;
		float curvature = 0; //amount to offset the track each frame
		float moveAmount = 0; //how much to move each frame and which direction
		float offset = 0;
		std::vector<Segment> trackData;
		int currentSect = 0;
		

		Segment baseSeg;
		

		static sf::Color grassLight;
		static sf::Color grassDark;
		static sf::Color roadLight;
		static sf::Color roadDark;
		static sf::Color tile_col_1;
		static sf::Color tile_col_2;

	
};


#endif
