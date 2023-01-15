#include "LeaderboardState.h"


LeaderboardState::LeaderboardState()
{
	trophySprite.setTexture(ImageManager::GetInstance()->trophyTexture);
	//trophySprite.setScale(0.09f, 0.09f);
	trophySprite.setPosition(sf::Vector2f(GameGlobals::GAME_W / 2-trophySprite.getGlobalBounds().width/2, GameGlobals::GAME_H / 2-trophySprite.getGlobalBounds().height/2));
	trophySprite.setColor(sf::Color(255, 255, 255, 64));
	ScoreSaveData scores;
	std::map<std::string, float> data = scores.getScores();
	std::vector<std::pair<std::string,float>> sorted = sortScoreData(data);
	table.loadData(sorted);
}



void LeaderboardState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Enter)
			quit();
	}
}

void LeaderboardState::update(const float& dt)
{

}

void LeaderboardState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(sf::Color::Black);
	renderer.rtx->draw(trophySprite);
	table.drawElement(*renderer.rtx);
	

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

std::vector<std::pair<std::string, float>> LeaderboardState::sortScoreData(std::map<std::string, float>& src)
{
	std::vector<std::pair<std::string, float>> sortedScores;
	for (auto it = src.begin(); it != src.end(); it++)
		sortedScores.push_back(*it);
	std::sort(sortedScores.begin(), sortedScores.end(), [](std::pair<std::string, float>& p1, std::pair<std::string, float>& p2) {return p1.second < p2.second; });
	return sortedScores;

}

void LeaderboardState::quit()
{
	exited = true;
}

int LeaderboardState::nextState()
{
	return -1;
}




