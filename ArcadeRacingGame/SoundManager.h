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

	sf::SoundBuffer nav_buf;
	sf::SoundBuffer select_buf;

	sf::SoundBuffer b1_buf;
	sf::SoundBuffer ch_buf;	

	sf::SoundBuffer explosion_buf;

public:
	SoundManager(const SoundManager& other) = delete;
	void operator=(const SoundManager&) = delete;

	static SoundManager* GetInstance();

	sf::Sound menuNavigate;
	sf::Sound menuSelect;

	sf::Music trackMusic1;
	sf::Sound beep_1;
	sf::Sound checkpoint;
	sf::Sound explosion;
	

};

#endif
