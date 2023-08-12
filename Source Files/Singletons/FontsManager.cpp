#include "FontsManager.h"

FontsManager* FontsManager::_fontsManager = nullptr;

FontsManager::FontsManager()
{
	if (!font_basic.loadFromFile("assets/Fonts/VT323.ttf") || !font_title.loadFromFile("assets/fonts/GravityBold.ttf"))
	{
		std::cout << "could not load fonts" << '\n';

	}
}

FontsManager::~FontsManager()
{
	delete _fontsManager;
}

FontsManager* FontsManager::GetInstance()
{
	if (_fontsManager == nullptr)
		_fontsManager = new FontsManager();
	return _fontsManager;
}
