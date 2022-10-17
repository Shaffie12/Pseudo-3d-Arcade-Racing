#ifndef _UTIL_H_
#define _UTIL_H_
#include <algorithm>
#include <cmath>

namespace Racing
{
	class Util
	{
	public:
		static float roundToDP(float val, float p);
		static float Lerp(float a, float b, float t);
		static float clamp(float n, float lower, float upper);
		static float convertRange(float valToConvert, float oldMin, float oldMax, float newMin, float newMax);
		
		
	};
}


#endif
