#ifndef _OPTIONS_STATE_H_
#define _OPTIONS_STATE_H_
#include "State.h"

class OptionsState: public State
{
public:
	void handleInput(sf::Event& e) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	void quit() override;
	int nextState() override;
};

#endif 
