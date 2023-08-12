#include "Util.h"


float Racing::Util::Lerp(float a, float b, float t){ return a + (b - a) * t; }
float Racing::Util::clamp(float n, float lower, float upper) 
{ 

	return std::max(lower, std::min(n, upper));

}
float Racing::Util::roundToDP(float val, float prec) 
{ 
	float power = pow(10, prec);
	return round(val * power) / power;
}

float Racing::Util::convertRange(float valToConvert, float oldMin, float oldMax, float newMin, float newMax)
{
	return(((valToConvert - oldMin) * (newMax - newMin)) / (oldMax - oldMin)) + newMin;
}

