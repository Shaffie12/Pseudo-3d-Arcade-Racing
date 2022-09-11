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
		void adjustRoadSpeed(float playerPosition);
		static float trackCurvature;
		static float speed; //artificially represent speed of player
		static float dist; //artificially represents how far player has moved


	
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
				scaledY = ((y - (GameGlobals::SCREEN_H / 2)) / (GameGlobals::SCREEN_H - (GameGlobals::SCREEN_H / 2))) ; //scale 300-600 as 0-1
				perspective = minRoad +scaledY *road_w;
				//i think the colours need to be redrawn every frame too
				tile_w = perspective * 0.15;
				
			}
		};

		struct Segment
		{
			float t_curvature;
			float distanceToReach;
			int position;
			Segment(float curvature, float distance) : position(GameGlobals::SCREEN_H / 2) { t_curvature = curvature; distanceToReach = distance; }
			Segment(const Segment& s) { this->distanceToReach = s.distanceToReach; this->position = GameGlobals::SCREEN_H / 2; this->t_curvature = s.t_curvature;  }
		};

		void drawTrackLines();
		void moveSegment();
		
		
		static float road_w;
		static float minRoad; //minimal amount of road at the highest point on road
		float middlePt = 0.5;
		
		std::vector<Line>* trackLines;
		float offset = 0;
		std::vector<Segment> trackData;
		std::vector<Line>::reverse_iterator rit;
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
