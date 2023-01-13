#ifndef _SAVEABLE_H_
#define _SAVEABLE_H_
#include <fstream>
#include <iostream>

class Saveable
{
protected:
	std::ofstream out;
	std::ifstream in;

	virtual void WriteToFile() = 0;
	virtual void ReadFromFile() = 0;
	
	
};
#endif 

