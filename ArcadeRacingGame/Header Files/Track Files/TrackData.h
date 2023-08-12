#ifndef _TRACKDATA_H_
#define _TRACKDATA_H_
#include "Segment.h"
#include "Sign.h"
#include "Rock.h"
#include "Tree.h"
#include "StartSign.h"
#include "Sign2.h"
#include "Sign3.h"

class TrackData 
{
	
public:
	int totalTrackLength = 0;
	std::vector<Segment> segments;
	std::map<std::string,sf::Color> colors; 
	//colours, theme tune etc..

	struct RoadSideTemplate
	{
		enum ObjectType { Rock, Tree, Sign, Start, Sign2, Sign3 };

		RoadSideTemplate(ObjectType type, int segmentId, float depth, bool left, bool invert) { this->type = type; this->segmentId = segmentId; this->depth = depth; 
							this->left = left; this->invert = invert;}

		
		RoadSideTemplate(ObjectType type, int screeny, int segmentId, float depth, bool left, bool invert) { this->screeny = screeny; 
		this->type = type; this->segmentId = segmentId; this->depth = depth; this->left = left; this->invert = invert;}


		ObjectType type;
		bool left = false;
		int screeny = -1;
		int segmentId = 0;
		float depth = 0;
		bool invert = false;
	};
	std::vector<RoadSideTemplate> objects;

protected:
	void calculateTotalLength();
	


};


#endif 
