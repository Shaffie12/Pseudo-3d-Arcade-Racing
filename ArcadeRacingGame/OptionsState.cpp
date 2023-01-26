#include "OptionsState.h"

void OptionsState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Enter || e.key.code == sf::Keyboard::Space)
			quit();
	}
}

void OptionsState::update(const float& dt)
{
}

void OptionsState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(sf::Color::Black);

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

void OptionsState::quit()
{
	exited = true;
}

int OptionsState::nextState()
{
	return -1;
}
