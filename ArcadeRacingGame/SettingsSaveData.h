#ifndef _SETTINGS_SAVE_DATA_H_
#define _SEETTINGS_SAVE_DATA_H_
#include "Saveable.h"
#include <map>

class SettingsSaveData : public Saveable
{
	float stfVolume;
	float musicVolume;

public:
	SettingsSaveData();
	void WriteToFile() override;
	void ReadFromFile() override;
	void setSfxVolume(float& value);
	void setMusicVolume(float& value);
	
};

#endif 
