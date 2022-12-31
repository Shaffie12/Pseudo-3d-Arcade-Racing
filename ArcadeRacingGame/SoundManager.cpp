#include "SoundManager.h"


SoundManager* SoundManager::_soundManager = nullptr;

SoundManager::SoundManager()
{
	if (!b1_buf.loadFromFile("assets/sounds/beep1.wav") || !music_buf.loadFromFile("assets/sounds/music.wav") || (!ch_buf.loadFromFile("assets/sounds/check.wav")))
	{
		std::cout << "failed to load sounds";
	}
	beep_1.setBuffer(b1_buf);
	checkpoint.setBuffer(ch_buf);
}

SoundManager::~SoundManager()
{
	delete _soundManager;
}

SoundManager* SoundManager::GetInstance()
{
	if (_soundManager == nullptr)
		_soundManager = new SoundManager();
	return _soundManager;
}

