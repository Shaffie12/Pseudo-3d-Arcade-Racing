#ifndef _FONTS_MANAGER_H_
#define _FONTS_MANAGER_H_
#include <SFML/Graphics.hpp>
#include <iostream>

class FontsManager
{
private:
	FontsManager();
	~FontsManager();
	static FontsManager* _fontsManager;
	
public:
	FontsManager(FontsManager& other) = delete;
	void operator=(const FontsManager& other) = delete;

	static FontsManager* GetInstance();
	sf::Font font_basic;
	sf::Font font_title;


};
#endif 
