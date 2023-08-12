#include "SoundManager.h"


SoundManager* SoundManager::_soundManager = nullptr;

SoundManager::SoundManager()
{
	if (!b1_buf.loadFromFile("assets/sounds/beep1.wav") || 
		!music1.openFromFile("assets/sounds/music.wav") || 
		!ch_buf.loadFromFile("assets/sounds/check.wav") ||
		!nav_buf.loadFromFile("assets/sounds/nav.wav") ||
		!select_buf.loadFromFile("assets/sounds/select.wav") ||
		!explosion_buf.loadFromFile("assets/sounds/explode2.wav") ||
		!engine_buf.loadFromFile("assets/sounds/engineStable.wav")
		
		)
	{
		std::cout << "failed to load sounds";
	}
	menuNavigate.setBuffer(nav_buf);
	menuSelect.setBuffer(select_buf);
	menuSelect.setPitch(0.7f);

	beep_1.setBuffer(b1_buf);
	checkpoint.setBuffer(ch_buf);
	explosion.setBuffer(explosion_buf);
	engine.setBuffer(engine_buf);
	
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

