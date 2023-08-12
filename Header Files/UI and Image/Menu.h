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
	Menu(float width, float height, int numberOfElements, std::vector<std::string> menuItems, sf::Color color);
	void drawElement(sf::RenderTarget& w) override;
	void update(const float& dt) override;
	void MoveUp();
	void MoveDown();
	int getSelected();
	const sf::Vector2f GetElementPosition(int element) { return menuTexts[element].getPosition(); }
	void SetTextScale(float x, float y);
	int getNumberOfElements();
	sf::Color color;
	sf::Text menuTexts[MAX_ELEMENTS];
	float yPadding = 30.0f;
	bool enabled = false;



};
#endif

