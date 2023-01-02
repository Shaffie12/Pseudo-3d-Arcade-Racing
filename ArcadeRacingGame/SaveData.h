#ifndef _SAVEDATA_H_
#define _SAVEDATA_H_

class SaveData
{
public:
	void writeScore(float& score);
	void writeSettings();
private:
	float timeScore = 0;


};

#endif

