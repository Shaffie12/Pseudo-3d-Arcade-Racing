#include "GameOverState.h"

GameOverState::GameOverState()
{
	
	if (!textFont.loadFromFile("assets/Fonts/VT323.ttf"))
	{
		std::cout << "could not load fonts" << '\n';

	}
	bgFill = sf::Color::Black;
	gameOverText.setString("GAME OVER");
	gameOverText.setFont(textFont);
	gameOverText.setScale(1, 1);
	gameOverText.setPosition(GameGlobals::GAME_W / 2 - gameOverText.getGlobalBounds().width/2,
		GameGlobals::GAME_H / 2 - gameOverText.getGlobalBounds().height/2);
	gameOverText.setFillColor(sf::Color::White);
	
}

void GameOverState::handleInput(const float& dt)
{
}

void GameOverState::update(const float& dt)
{
}

void GameOverState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(bgFill);
	renderer.rtx->draw(gameOverText);

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

int GameOverState::nextState()
{
	return 0;
}

void GameOverState::quit()
{
}
