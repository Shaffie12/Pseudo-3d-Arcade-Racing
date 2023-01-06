#ifndef _TITLE_STATE_H_
#define _TITLE_STATE_H_

#include "State.h"
#include "Menu.h"
#include "FontsManager.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>


class TitleState : public State
{
public:
	TitleState();
	void handleInput(sf::Event& e) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	int nextState() override;
	void quit() override;
private:
	sf::Color bgFill;
	sf::Text titleText;
	Menu menu;
	
	

};

#endif 