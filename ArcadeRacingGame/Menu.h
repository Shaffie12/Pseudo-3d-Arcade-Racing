#ifndef _MENU_H_
#define _MENU_H_
#include "Drawable.h"
#include "FontsManager.h"
#include "SoundManager.h"
#include <vector>
#include<string>
#include <iostream>


constexpr int MAX_ELEMENTS = 5;

class Menu : public Drawable
{

protected:
	int selected = 0;
	int elements = 0;
	float blink = 0;

public:
	Menu(float width, float height, int numberOfElements, std::vector<std::string> menuItems);
	void drawElement(sf::RenderTarget& w) override;
	void update(const float& dt) override;
	void MoveUp();
	void MoveDown();
	int getSelected();
	int getNumberOfElements();
	sf::Text menuTexts[MAX_ELEMENTS];
	bool enabled = false;



};
#endif

