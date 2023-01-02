#ifndef _SAVEABLE_H_
#define _SAVEABLE_H_
#include <fstream>
#include "SaveData.h"
#include "GameGlobals.h"
#include <iostream>

class Saveable
{
protected:
	std::ofstream out;
	std::ifstream in;
	virtual SaveData WriteSaveData() = 0;
	void WriteToFile(SaveData& sd);
	SaveData ReadFromFile();
	
		
	
};
#endif 

