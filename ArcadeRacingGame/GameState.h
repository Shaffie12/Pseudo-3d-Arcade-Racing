#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include "State.h"
#include "Drawable.h"
#include "Player.h"
#include "Track.h"
#include "TrackData.h"
#include "Background.h"
#include "UI.h"


class GameState : public State
{
public:
	GameState(TrackData trackData);

	void handleInput(sf::Event& e) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	int nextState() override;
	void quit() override;

private:
	Track track;
	Player player;
	Background bg;
	UI ui;
	std::vector<RoadObject> road_objects;
	const int TIMER_START = 80;
	float raceTimer;
	bool intro;
	bool moving = false;
	bool left = false;
	bool right = false;

	void updateUI();
	void decrementRaceTimer(float dt);
	bool isGameFinished();
	




};
#endif