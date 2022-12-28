#ifndef _TREE_H_
#define _TREE_H_
#include "RoadObject.h"

class Tree : public RoadObject
{
public:
	Tree(int screeeny, int segmentId, float depth, bool left);
	Tree(int segmentId, float depth, bool left);
	
};


#endif 
