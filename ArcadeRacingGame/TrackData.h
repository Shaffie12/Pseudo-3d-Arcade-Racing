#ifndef _TRACKDATA_H_
#define _TRACKDATA_H_
#include "Segment.h"
#include "Sign.h"
#include "Rock.h"
#include "Tree.h"

class TrackData //this should never be instantiated
{
	
public:
	TrackData();
	int totalTrackLength = 0;
	std::vector<Segment> segments;
	std::vector<RoadObject> objects;
	std::map<std::string,sf::Color> colors; 
	//colours, theme tune etc..

protected:
	void calculateTotalLength();

};


#endif 
