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
		void addDist(float amount);
		float getDist();
		void getNextCurvature();


	
	private:
		struct Line 
		{ 
			sf::Vertex vertices[10]; 
			sf::Color colours[3];
			int y; //i dont think it needs this since its always passed it
			float pos_before_move;
			float perspective;
			float tile_w;
			float offset;
			Line(int yval) : tile_w(road_w * 0.15f), y(yval), pos_before_move(0.5f), offset(0)
			{
				float scaledY = ((y - (GameGlobals::SCREEN_H / 2)) / (GameGlobals::SCREEN_H - (GameGlobals::SCREEN_H / 2)));
				perspective = Track::minRoad + scaledY * Track::percentOfPersp; //calculate perspective
				//i think the colours need to be redrawn every frame too
				
			}
		};

		struct Segment
		{
			float t_curvature;
			float distanceToReach;
			float position;
			Segment(float curvature, float distToReach) : position(GameGlobals::SCREEN_H / 2) { t_curvature = curvature; distanceToReach = distToReach; }
		};

		void drawTrackLines();
		void moveSegment();
		
		
		static float road_w;
		static float minRoad; //minimal amount of road at the highest point on road
		static float percentOfPersp;; // change view toward ground or sky
		float middlePt = 0.5f;
		float dist = 0 ;//artificially represents how far player has moved
		std::vector<Line>* trackLines;

		bool activeSegment = false;
		float segPosition = GameGlobals::SCREEN_H / 2; //there may be limiatations to just using 1 segment as you have to wait for it to hit the bottom of the screen before you introduce a new curve
		float baseSegOffset = 0.5f;

		float curvature = 0; //amount to offset the track each frame
		float moveAmount = 0;
		
		std::vector<std::pair<float, float>> trackData;
		int currentSect = 0;

		static sf::Color grassLight;
		static sf::Color grassDark;
		static sf::Color roadLight;
		static sf::Color roadDark;
		static sf::Color tile_col_1;
		static sf::Color tile_col_2;

	
};


#endif
