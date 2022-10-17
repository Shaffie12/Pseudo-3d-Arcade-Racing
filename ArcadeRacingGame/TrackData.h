#ifndef _TRACKDATA_H_
#define _TRACKDATA_H_
#include "Segment.h"
#include "Tree.h"
#include <string>



class TrackData
{
	
public:
	TrackData();
	std::vector<Segment> segments;
	std::vector<std::pair<sf::Color, std::string>> colors;
	//colours, theme tune etc..

};


#endif 
