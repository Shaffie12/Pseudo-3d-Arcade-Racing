#include "TitleState.h"



TitleState::TitleState() : menu(GameGlobals::GAME_W, 177, 3, {"START", "LEADERBOARD", "OPTIONS"}),track(sample.colors, sample.segments,sample.totalTrackLength)
{
	
	bgFill = sf::Color::Cyan;

	titleText.setString("ARCADE RACER LITE");
	titleText.setFont(FontsManager::GetInstance()->font_title);
	titleText.setFillColor(sf::Color::Black);
	titleText.setPosition(GameGlobals::GAME_W/2-titleText.getGlobalBounds().width/2, (GameGlobals::GAME_H/2-titleText.getGlobalBounds().height/2)-100);
	titleText.setScale(sf::Vector2f(1, 1));	

	

}

void TitleState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::W)
			menu.MoveUp();
		else if (e.key.code == sf::Keyboard::S)
			menu.MoveDown();
		else if (e.key.code == sf::Keyboard::Enter && menu.getSelected() == 0)
		{
			SoundManager::GetInstance()->menuSelect.play();
			quit();
		}
			
	}

}

void TitleState::update(const float& dt)
{
	menu.update(dt);
	track.acceleration += 1 * dt;
	track.update(dt);
}

void TitleState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear();
	bg.drawElement(*renderer.rtx);
	renderer.rtx->draw(titleText);
	track.drawElement(*renderer.rtx);
	menu.drawElement(*renderer.rtx);
	

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
	exited = true;
}
