#ifndef _LEADERBOARD_STATE_H_
#define _LEADERBOARD_STATE_H_
#include <vector>
#include <string>
#include "State.h"
#include "Table.h"
#include "ScoreSaveData.h"


class LeaderboardState : public State
{

	Table table;
	std::vector<std::pair<std::string,float>> sortScoreData(std::map<std::string,float>& src);
		
public:
	LeaderboardState();
	void handleInput(sf::Event& e) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	void quit() override;
	int nextState() override;
};

#endif 
