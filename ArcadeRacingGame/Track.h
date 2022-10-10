#ifndef TRACK_H_
#define TRACK_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Util.h"

#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>

class Track :public Drawable
{
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
			float screenY;
			Line(int yval) : y(yval), middlePt(0.5)
			{
			
				scaledY = Racing::Util::convertRange(y, 1, GameGlobals::GAME_H/2, 0, 1);
				perspective = minRoad + scaledY * road_w;
				screenY = y + GameGlobals::GAME_H / 2;
				tile_w = perspective * 0.15;
				
				
				
				
			}
		};

		struct Segment
		{
			float t_curvature;
			float distanceToReach;
			float position;
			float roadOffset;
			Segment(float curvature, float distance) : position(GameGlobals::GAME_H / 2) { t_curvature = curvature; distanceToReach = distance; roadOffset = curvature; }
			Segment(const Segment& s) { this->distanceToReach = s.distanceToReach; this->position = GameGlobals::GAME_H / 2; this->t_curvature = s.t_curvature; this->roadOffset = s.roadOffset; }
		};
		//list of items here?  though ideally we would want multiple tracks, in which case we need to abstract the entire track class.
		//foppy has the track simply be a list of segments. where segments have a ddx, length and a list of items(items have count, type, start depth, dz?

		void update();
		void moveSegment();
		void addSegmentOffset();
		void nextSegment();
		
		
		float diff = 0;
		static float road_w;
		static float minRoad; //minimal amount of road at the highest point on road
		float middlePt = 0.5;
		bool move = false;
		
		std::vector<Line>* trackLines;
		
		std::vector<Segment> trackData;
		std::vector<Line>::reverse_iterator rit;
		int currentSect = 0;
		
		

		static sf::Color grassLight;
		static sf::Color grassDark;
		static sf::Color roadLight;
		static sf::Color roadDark;
		static sf::Color tile_col_1;
		static sf::Color tile_col_2;

public:
	Track();
	virtual void drawElement(sf::RenderTarget& w) override;
	void addPlayerOffset(float amount, bool add);
	void addSpeed(float amount, bool add);
	static float segmentAmt;
	static Segment baseSeg;

	static float trackCurvature;
	static float speed; //artificially represent speed of player
	static float dist; //artificially represents how far player has moved
	static float globalOffset;

		
	
};




#endif
