#include "TrackData.h"

TrackData::TrackData() {}
void TrackData::calculateTotalLength()
{
    for (Segment s : segments)
        totalTrackLength += s.length;
}
;


