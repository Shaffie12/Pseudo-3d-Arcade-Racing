#include "Saveable.h"


void Saveable::WriteToFile(SaveData& sd)
{
	out.open(GameGlobals::SAVE_LOC, std::ios::app);
	float time = sd.timeScore;
	out << sd.timeScore << '\n';
	//also pipe settings
	out.close();

}

SaveData Saveable::ReadFromFile()
{
	SaveData data;
	float score;
	in.open(GameGlobals::SAVE_LOC);
	if (in)
	{
		while(in)
		{
			std::string next;
			
			in >> next;
			if(next.size()>0)
				data.timeScore = std::stof(next);

		}
		
	}
	in.close();
	return data;

}
