#ifndef _TITLE_STATE_H_
#define _TITLE_STATE_H_

#include "State.h"
#include "Menu.h"
#include "TextInput.h"
#include "Track.h"
#include "SampleTrack.h"
#include "Background.h"
#include "FontsManager.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

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
	sf::Text titleText;
	SampleTrack sample;
	Track track;
	Menu menu;
	TextInput userName;
	Background bg;
	
	
	

};

#endif 