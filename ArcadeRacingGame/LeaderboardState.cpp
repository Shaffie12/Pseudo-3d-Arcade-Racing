#include "LeaderboardState.h"

std::vector<std::pair<std::string, float>> LeaderboardState::sortScoreData(std::map<std::string, float>& src)
{
	std::vector<std::pair<std::string, float>> sortedScores;
	for (auto it = src.begin(); it != src.end(); it++)
		sortedScores.push_back(*it);
	std::sort(sortedScores.begin(), sortedScores.end(), [](std::pair<std::string, float>& p1, std::pair<std::string, float>& p2) {return p1.second < p2.second; });
	return sortedScores;

}

LeaderboardState::LeaderboardState()
{
	ScoreSaveData scores;
	std::map<std::string, float> data = scores.getScores();
	std::vector<std::pair<std::string,float>> sorted = sortScoreData(data);
	table.loadData(sorted);
}

void LeaderboardState::handleInput(sf::Event& e)
{
}

void LeaderboardState::update(const float& dt)
{
}

void LeaderboardState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(sf::Color::Black);
	table.drawElement(*renderer.rtx);

	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}



void LeaderboardState::quit()
{
	exited = true;
}

int LeaderboardState::nextState()
{
	return 0;
}




