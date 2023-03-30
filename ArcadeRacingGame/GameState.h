#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include "State.h"
#include "Drawable.h"
#include "Player.h"
#include "NpcRacer.h"
#include "Track.h"
#include "TrackData.h"
#include "Background.h"
#include "RoadObjectLinker.h"
#include "UI.h"


class GameState : public State
{
public:
	GameState(TrackData trackData);
	GameState(TrackData trackdata, std::string username);
	void handleInput(sf::Event& e) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	int nextState() override;
	void quit() override;
	static const int REQUIRED_LAPS;
	float raceTimer;
	
private:
	Track track;
	Player player;
	std::vector<NpcRacer*> npcs; 
	Background bg;
	UI ui;
	RoadObjectLinker roadObjectsContainer;
	const int TIMER_START = 80;
	
	int laps = 0;
	bool moving = false;
	bool left = false;
	bool right = false;
	bool intro = true;

	float beep_timer = 0.0f;
	const float INITIAL_WAIT = 4.1f*1000.0f;
	bool beeps[3] = { false,false,false};

	std::string username;

	void sendVarsToUI();
	void decrementRaceTimer(float dt);
	void incrementRaceTimer(float amount);
	bool isGameFinished();
	void checkPlayerMovement(const float& dt);
	void doIntroBeeps(const float& dt);
	void doColiisionDetection(RoadObject*& r);
	void doCollisionDetection(NpcRacer*& r);
	




};
#endif