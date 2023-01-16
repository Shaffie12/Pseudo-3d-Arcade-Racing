#include "RoadObjectLinker.h"

RoadObjectLinker::RoadObjectLinker(std::vector<TrackData::RoadSideTemplate> objs, Track& t) : track(t)
{
	for (const TrackData::RoadSideTemplate& temp : objs)
	{
		switch (temp.type)
		{
		case TrackData::RoadSideTemplate::Tree:
			if (temp.screeny != -1)
				objects.push_back(new Tree(temp.screeny, temp.segmentId, temp.depth, temp.left, track));
			else
				objects.push_back(new Tree(temp.segmentId, temp.depth, temp.left, track));
			break;
		case TrackData::RoadSideTemplate::Rock:
			if (temp.screeny != -1)
				objects.push_back(new Rock(temp.screeny, temp.segmentId, temp.depth, temp.left, track));
			else
				objects.push_back(new Rock(temp.segmentId, temp.depth, temp.left, track));
			break;
		case TrackData::RoadSideTemplate::Sign:
			if (temp.screeny != -1)
				objects.push_back(new Sign(temp.screeny, temp.segmentId, temp.depth, temp.left, track));
			else
				objects.push_back(new Sign(temp.segmentId, temp.depth, temp.left, track));
			break;
		case TrackData::RoadSideTemplate::Start:
			if (temp.screeny != -1)
				objects.push_back(new StartSign(temp.screeny, temp.segmentId, temp.depth, temp.left, track));
			else
				objects.push_back(new StartSign(temp.segmentId, temp.depth, temp.left, track));
			break;
		}
	}
	
}
