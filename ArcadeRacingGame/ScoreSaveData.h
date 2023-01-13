#ifndef _SCORE_SAVE_DATA_H_
#define _SCORE_SAVE_DATA_H_
#include <map>
#include <string>
#include "Saveable.h"

class ScoreSaveData  : public Saveable
{
	std::map<std::string, float> scores;
	const std::string SCORE_SAVE_PATH = "Savedata/save.txt";

public:
	ScoreSaveData();
	std::map<std::string, float> getScores() const;
	void WriteToFile() override;
	void ReadFromFile() override;
	

	
	
};
#endif
