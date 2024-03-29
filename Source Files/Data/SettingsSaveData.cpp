#include "SettingsSaveData.h"

SettingsSaveData::SettingsSaveData()
{
	ReadFromFile();
}

void SettingsSaveData::WriteToFile()
{
	out.open(SETTINGS_SAVE_PATH, std::ios::trunc);
	out << musicVolume << '\n' << sfxVolume << '\n' << controller;

	out.close();
}

void SettingsSaveData::ReadFromFile()
{
	std::string next;
	float musicVol, sfxVol;
	bool useController;
	musicVol = sfxVol = 1.0f;
	useController = 0;

	in.open(SettingsSaveData::SETTINGS_SAVE_PATH);
	if (in)
	{


		in >> next;
		if (next.size() > 0)
		{
			try
			{
				musicVol = stof(next);
			}
			catch (std::invalid_argument) { std::cout << "could not convert settings data" << '\n'; }
		}
		next.clear();
		in >> next;
		if (next.size() > 0)
		{
			try
			{
				sfxVol = stof(next);
			}
			catch (std::invalid_argument) { std::cout << "could not convert settings data" << '\n'; }
		}
		next.clear();
		in >> next;
		if (next.size() > 0)
		{
			try
			{
				int read_int = std::stoi(next);
				if (read_int >= 1)
					useController = true;
				else
					useController = false;

			}
			catch (std::invalid_argument) { std::cout << "could not convert settings data" << '\n'; }
		}


		musicVolume = musicVol;
		sfxVolume = sfxVol;
		controller = useController;
	}
	in.close();
}

void SettingsSaveData::setSfxVolume(float& value){sfxVolume = value;}

void SettingsSaveData::setMusicVolume(float& value){musicVolume = value;}

void SettingsSaveData::setController(bool& value) { controller = value; }

const float SettingsSaveData::getSfxVolume() const
{
	return sfxVolume;
}

const float SettingsSaveData::getMusicVolume() const
{
	return musicVolume;
}

const bool SettingsSaveData::getControllerSettings() const
{
	return controller;
}
