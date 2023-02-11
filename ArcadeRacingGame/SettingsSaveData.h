#ifndef _SETTINGS_SAVE_DATA_H_
#define _SEETTINGS_SAVE_DATA_H_
#include "Saveable.h"
#include <map>
#include <utility>
#include <string>

class SettingsSaveData : public Saveable
{
	const std::string SETTINGS_SAVE_PATH = "GameSettings/settings.txt";
	float sfxVolume;
	float musicVolume;

public:
	SettingsSaveData();
	void WriteToFile() override;
	void ReadFromFile() override;
	void setSfxVolume(float& value);
	void setMusicVolume(float& value);
	const float getSfxVolume() const;
	const float getMusicVolume() const;
	
};

#endif 
