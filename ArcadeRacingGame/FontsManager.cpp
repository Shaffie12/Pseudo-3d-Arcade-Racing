#include "FontsManager.h"


FontsManager::FontsManager()
{
	if (!font.loadFromFile("assets/Fonts/VT323.ttf"))
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
