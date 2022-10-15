#ifndef _TRACKDATA_H_
#define _TRACKDATA_H_
#include "Segment.h"
class TrackData
{
	//foppy ref.  list of segments .
public:
	TrackData();
protected:
	std::vector<Segment> segments;
	//colours, theme tune etc..

};


#endif 
