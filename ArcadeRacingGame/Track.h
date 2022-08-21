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
			Line(float persp, float distance)
			{
				colours[0] = sinf(15 * pow(1 - persp, 10) + distance * 0.1) > 0.0f ? grassLight : grassDark; 
				colours[1] =  sinf(50 * pow(1 - persp, 5) + distance * 0.7) > 0.0f ? tile_col_1 : tile_col_2; 
				colours[2] = sinf(50 * pow(1 - persp, 5) + distance * 0.7) > 0.0f ? roadLight : roadDark;
			}
		};
		Line drawTrackLine(int y, float middlePt, float persp);
		void moveSegment();

		float road_w = 0.8f;
		float tile_w = road_w * 0.15f;
		float mid = 0.5f;
		float minRoad = 0.01; //minimal amount of road at the highest point on road
		float percentOfPersp = 0.5f; // change view toward ground or sky
		float dist = 0 ;//artificially represents how far player has moved

		float segPosition = GameGlobals::SCREEN_H / 2;
		float baseSegOffset = 0.5f;
		float curvature = 0;
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
