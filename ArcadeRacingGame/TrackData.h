#ifndef _TRACKDATA_H_
#define _TRACKDATA_H_
#include "Segment.h"
#include "Tree.h"
#include <string>



class TrackData //this should never be instantiated
{
	
public:
	TrackData();
	std::vector<Segment> segments;
	std::map<std::string,sf::Color> colors; 
	//colours, theme tune etc..

};


#endif 
