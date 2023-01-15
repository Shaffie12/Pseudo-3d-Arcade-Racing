#include "OptionsState.h"

void OptionsState::handleInput(sf::Event& e)
{
}

void OptionsState::update(const float& dt)
{
}

void OptionsState::drawToTexture(Renderer& renderer)
{
}

void OptionsState::quit()
{
	exited = true;
}

int OptionsState::nextState()
{
	return -1;
}
