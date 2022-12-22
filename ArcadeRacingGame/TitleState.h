#ifndef _TITLE_STATE_H_
#define _TITLE_STATE_H_

#include "State.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>

class TitleState : public State
{
public:
	TitleState();
	void handleInput(const float& dt) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	int nextState() override;
	void quit() override;
private:
	float blink;
	sf::Color bgFill;
	sf::Font titleFont;
	sf::Text titleText;
	sf::Text optionsText;
	sf::Text startText;

};

#endif 