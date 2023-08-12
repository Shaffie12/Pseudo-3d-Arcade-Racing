#ifndef _ROAD_OBJECT_LINKER_H_
#define _ROAD_OBJECT_LINKER_H_
#include "TrackData.h"
#include "Track.h"
#include "RoadObject.h"
#include <vector>

class RoadObjectLinker
{
public:
	RoadObjectLinker(std::vector<TrackData::RoadSideTemplate> objs, Track& t);
	std::vector<RoadObject*> objects;
	Track& track;
};
#endif 
