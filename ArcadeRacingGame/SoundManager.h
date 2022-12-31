#ifndef _SOUND_MANAGER_H_
#define _SOUND_MANAGER_H_
#include<SFML/Audio.hpp>
#include <iostream>

class SoundManager
{
private:
	SoundManager();
	~SoundManager();
	static SoundManager* _soundManager;

	sf::SoundBuffer music_buf;
	sf::SoundBuffer b1_buf;
	sf::SoundBuffer ch_buf;
	

public:
	SoundManager(SoundManager& other) = delete;
	void operator=(const SoundManager&) = delete;

	static SoundManager* GetInstance();

	sf::Music music;
	sf::Sound beep_1;
	sf::Sound checkpoint;

};

#endif
