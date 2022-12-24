#include "WinState.h"

WinState::WinState()
{
	if (!textFont.loadFromFile("assets/Fonts/VT323.ttf"))
	{
		std::cout << "could not load fonts" << '\n';

	}

	bgFill = sf::Color::Yellow;
	winText.setString("YOU WIN");
	winText.setFont(textFont);
	winText.setScale(1, 1);
	winText.setPosition(GameGlobals::GAME_W / 2 - winText.getGlobalBounds().width / 2,
		GameGlobals::GAME_H / 2 - winText.getGlobalBounds().height / 2);
	winText.setFillColor(sf::Color::Black);
}

void WinState::handleInput(sf::Event& e)
{
}

void WinState::update(const float& dt)
{
}

void WinState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(bgFill);
	renderer.rtx->draw(winText);

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

void WinState::quit()
{
}

int WinState::nextState()
{
	return 0;
}
