#ifndef _TITLE_STATE_H_
#define _TITLE_STATE_H_

#include "State.h"
#include "Menu.h"
#include "TextInput.h"
#include "Track.h"
#include "Background.h"
#include "SampleTrack.h"
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
	sf::Color bgFill;
	sf::Text titleText;
	Menu menu;
	TextInput userName;
	const SampleTrack sample = SampleTrack();
	Background bg = Background(std::rand() %16);
	Track track;
	

};

#endif 