#ifndef _SCORE_SAVE_DATA_H_
#define _SCORE_SAVE_DATA_H_
#include <map>
#include <string>
#include <utility>
#include "Saveable.h"

class ScoreSaveData  : public Saveable
{
	const std::string SCORE_SAVE_PATH = "Savedata/leaderboard.txt";
	std::map<std::string, float> scores;
	std::pair<std::string, float> nextEntry;

public:
	ScoreSaveData();
	std::map<std::string, float> getScores() const;
	void WriteToFile() override;
	void ReadFromFile() override;
	void MakeEntry(std::pair<std::string,float>& entry);
	

	
	
};
#endif
