#include "WinState.h"

WinState::WinState(float& timer)
{
	bgFill = sf::Color::Yellow;
	
	formatWinText();
	formatScore(timer);
}

WinState::WinState(float& timer, std::string username)
{
	
	bgFill = sf::Color::Yellow;

	formatWinText();
	formatScore(timer);

	//this should be a new fn
	float time = 80.0f - timer;

	ScoreSaveData data;
	std::pair<std::string, float> val = std::make_pair(username, time);
	data.MakeEntry(val);
	
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
	winText.setFont(FontsManager::GetInstance()->font_basic);
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
	timerText.setFont(FontsManager::GetInstance()->font_basic);
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
	return -2;
}

/*/
SaveData* WinState::ReadFromFile(const std::string& path)
{
	ScoreSaveData* data = new ScoreSaveData;
	float score;
	in.open(ScoreSaveData::SCORE_SAVE_PATH);
	if (in)
	{
		while (in)
		{
			std::string next;

			in >> next;
			if (next.size() > 0)
			{
				try
				{
					std::stof(next);
				}
				catch (std::invalid_argument e)
				{

				}
			}


		}

	}
	in.close();
	return data;
}
*/
