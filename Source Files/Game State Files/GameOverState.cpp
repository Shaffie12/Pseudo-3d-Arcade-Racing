#include "GameOverState.h"

GameOverState::GameOverState()
{
	bgFill = sf::Color::Black;
	gameOverText.setString("GAME OVER");
	gameOverText.setFont(FontsManager::GetInstance()->font_basic);
	gameOverText.setScale(1, 1);
	gameOverText.setPosition(GameGlobals::GAME_W / 2 - gameOverText.getGlobalBounds().width/2,
		GameGlobals::GAME_H / 2 - gameOverText.getGlobalBounds().height/2);
	gameOverText.setFillColor(sf::Color::White);

	restartText.setString("PRESS ENTER TO RETURN TO TITLE");
	restartText.setFont(FontsManager::GetInstance()->font_basic);
	restartText.setScale(1, 1);
	restartText.setPosition(GameGlobals::GAME_W / 2 - restartText.getGlobalBounds().width / 2,
		(GameGlobals::GAME_H / 2 - gameOverText.getGlobalBounds().height / 2) +100) ;
	restartText.setFillColor(sf::Color::White);
	
}

void GameOverState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Enter)
			quit();
	}
		
	
}

void GameOverState::update(const float& dt)
{
}

void GameOverState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(bgFill);
	renderer.rtx->draw(gameOverText);
	renderer.rtx->draw(restartText);

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

int GameOverState::nextState()
{
	return -2;
}

void GameOverState::quit()
{
	exited = true;
}
