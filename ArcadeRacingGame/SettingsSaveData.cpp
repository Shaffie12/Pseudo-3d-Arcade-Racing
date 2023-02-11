#include "SettingsSaveData.h"

SettingsSaveData::SettingsSaveData()
{
	ReadFromFile();
}

void SettingsSaveData::WriteToFile()
{
	out.open(SETTINGS_SAVE_PATH, std::ios::trunc);
	out << musicVolume << '\n' << sfxVolume;

	out.close();
}

void SettingsSaveData::ReadFromFile()
{
	std::string next;
	float musicVol, sfxVol;
	musicVol = sfxVol = 1.0f;

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

		musicVolume = musicVol;
		sfxVolume = sfxVol;
	}
	in.close();
}

void SettingsSaveData::setSfxVolume(float& value){sfxVolume = value;}

void SettingsSaveData::setMusicVolume(float& value){musicVolume = value;}

const float SettingsSaveData::getSfxVolume() const
{
	return sfxVolume;
}

const float SettingsSaveData::getMusicVolume() const
{
	return musicVolume;
}
