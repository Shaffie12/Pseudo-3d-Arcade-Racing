#ifndef _TEXT_INPUT_H_
#define _TEXT_INPUT_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "FontsManager.h"
#include <sstream>
#include <iostream>

class TextInput : public Drawable
{
	
	float blink = 0;
	std::stringstream input;
	int getBufSize();

public:
	TextInput();
	sf::Text text;
	void update(const float& dt) override;
	void drawElement(sf::RenderTarget& w) override;
	void handleInput(sf::Event& e);


};

#endif
