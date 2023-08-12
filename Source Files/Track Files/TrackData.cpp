#include "TrackData.h"

void TrackData::calculateTotalLength()
{
    for (Segment s : segments)
        totalTrackLength += s.length;
}


