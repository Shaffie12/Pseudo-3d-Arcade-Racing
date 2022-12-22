#include "TitleState.h"

TitleState::TitleState() : State()
{
	
	if (!titleFont.loadFromFile("assets/Fonts/VT323.ttf"))
	{
		std::cout << "could not load fonts" << '\n';

	}
	blink = 0;
	bgFill = sf::Color::Cyan;
	titleText.setString("TITLE SCREEN");
	titleText.setFont(titleFont);
	titleText.setFillColor(sf::Color::Black);
	titleText.setPosition(GameGlobals::GAME_W/2-titleText.getGlobalBounds().width/2, GameGlobals::GAME_H/2-titleText.getGlobalBounds().height/2);
	titleText.setScale(sf::Vector2f(1, 1));

}

void TitleState::handleInput(const float& dt)
{
}

void TitleState::update(const float& dt)
{
	blink += dt;
	sf::Color newCol = sinf(5 * blink) > 0 ? sf::Color::Transparent : sf::Color::Black;
	titleText.setFillColor(newCol);
		
}

void TitleState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(bgFill);
	renderer.rtx->draw(titleText);

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

int TitleState::nextState()
{
	return 0;
}

void TitleState::quit()
{
}
