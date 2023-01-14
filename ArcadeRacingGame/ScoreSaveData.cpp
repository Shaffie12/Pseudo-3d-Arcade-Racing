#include "ScoreSaveData.h"

ScoreSaveData::ScoreSaveData()
{
	ReadFromFile();
}

std::map<std::string, float> ScoreSaveData::getScores() const
{
	return scores;
}

void ScoreSaveData::WriteToFile()
{
}

void ScoreSaveData::ReadFromFile()
{
	float score;
	std::string next;
	
	in.open(ScoreSaveData::SCORE_SAVE_PATH);
	if (in)
	{
		while (in)
		{
			next.clear();
			in >> next;
			if (next.size() > 0)
			{
				try
				{
					score = stof(next.substr(next.find(';') + 1));
					
				}
				catch (std::invalid_argument) { std::cout << "could not convert score data" << '\n'; score = 0; }

				scores.insert(std::pair<std::string,float>(next.substr(0,next.find(';')), score));
			}


		}

	}
	in.close();
}
