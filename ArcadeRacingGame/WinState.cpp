#include "WinState.h"

WinState::WinState(float& timer)
{
	score = timer;
	bgFill = sf::Color::Yellow;
	
	formatWinText();
	formatScore(timer);
	SaveData data = WriteSaveData();
	WriteToFile(data);
	
}

void WinState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if(e.key.code == sf::Keyboard::Enter || e.key.code == sf::Keyboard::Space)
			quit();
	}
}

void WinState::update(const float& dt)
{
}

void WinState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(bgFill);
	renderer.rtx->draw(winText);
	renderer.rtx->draw(timerText);

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

void WinState::formatWinText()
{
	winText.setString("WIN!");
	winText.setFont(FontsManager::GetInstance()->font);
	winText.setScale(1, 1);
	winText.setPosition(GameGlobals::GAME_W / 2 - winText.getGlobalBounds().width / 2,
		GameGlobals::GAME_H / 2 - winText.getGlobalBounds().height / 2);
	winText.setFillColor(sf::Color::Black);
}

void WinState::formatScore(float& timer)
{
	std::stringstream s;
	s << std::fixed << std::setprecision(2) << 80.0f - timer;
	std::string time = s.str();
	timerText.setString("Your time was: " + time + " seconds. ");
	timerText.setFont(FontsManager::GetInstance()->font);
	timerText.setScale(1, 1);
	timerText.setPosition(GameGlobals::GAME_W / 2 - timerText.getGlobalBounds().width / 2, GameGlobals::GAME_H / 2 + 60);
	timerText.setFillColor(sf::Color::Black);
}

void WinState::quit()
{
	exited = true;
}

int WinState::nextState()
{
	return 0;
}

SaveData WinState::WriteSaveData()
{
	SaveData data = ReadFromFile();
	float time = 80.0f - score;
	data.writeScore(time);
	return data;
	
}
