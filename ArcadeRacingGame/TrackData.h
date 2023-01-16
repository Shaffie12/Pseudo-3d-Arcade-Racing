#ifndef _TRACKDATA_H_
#define _TRACKDATA_H_
#include "Segment.h"
#include "Sign.h"
#include "Rock.h"
#include "Tree.h"
#include "StartSign.h"

class TrackData 
{
	
public:
	int totalTrackLength = 0;
	std::vector<Segment> segments;
	std::map<std::string,sf::Color> colors; 
	//colours, theme tune etc..

	struct RoadSideTemplate
	{
		enum ObjectType { Rock, Tree, Sign, Start };

		RoadSideTemplate(ObjectType type, int segmentId, float depth, bool left) { this->type = type; this->segmentId = segmentId; this->depth = depth; this->left = left; }
		RoadSideTemplate(ObjectType type, int screeny, int segmentId, float depth, bool left) { this->screeny = screeny; this->type = type; this->segmentId = segmentId; this->depth = depth; this->left = left; }
		ObjectType type;
		bool left = false;
		int screeny = -1;
		int segmentId = 0;
		float depth = 0;
	};
	std::vector<RoadSideTemplate> objects;

protected:
	void calculateTotalLength();
	


};


#endif 
