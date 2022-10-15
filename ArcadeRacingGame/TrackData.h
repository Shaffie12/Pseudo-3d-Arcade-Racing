#ifndef _TRACKDATA_H_
#define _TRACKDATA_H_
#include <vector>
#include "Tree.h"

class TrackData
{
	public:
		TrackData(int trackNumber);
		std::vector<std::pair<float, float>> road_curve;
		std::vector<RoadObject> road_objects; 
		sf::Color roadCol;


	private:
};
#endif

