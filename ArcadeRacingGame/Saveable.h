#ifndef _SAVEABLE_H_
#define _SAVEABLE_H_
#include <fstream>
#include "SaveData.h"

class Saveable
{
protected:
	std::ofstream out;
public:
	virtual void WriteSaveData() = 0;
	void WriteToFile(SaveData sd) 
	{
	}
};
#endif 

