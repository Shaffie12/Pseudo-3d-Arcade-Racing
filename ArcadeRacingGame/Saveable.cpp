#include "Saveable.h"

/*
void Saveable::WriteToFile(SaveData& sd)
{
	out.open(GameGlobals::SAVE_LOC, std::ios::app);
	out << sd.username<<';'<< sd.timeScore << '\n';
	
	out.close();

}
*/

/*

SaveData* Saveable::ReadFromFile(const std::string& path)
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
			if (next.size() > 0)
			{
				try
				{
					std::stof(next);
				}
				catch (std::invalid_argument e)
				{

				}
			}
				

		}
		
	}
	in.close();
	return data;

}
*/