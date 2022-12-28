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
	const int TIMER_START = 5;
	float raceTimer;
	bool moving = false;
	bool left = false;
	bool right = false;
	bool intro = true;

	float beep_timer = 0.0f;
	const float INITIAL_WAIT = 4.1f*1000.0f;
	bool beeps[3] = { false,false,false};
	sf::SoundBuffer b1_buf;
	sf::SoundBuffer music_buf;
	sf::Sound beep_1;
	sf::Music music;

	void sendVarsToUI();
	void decrementRaceTimer(float dt);
	bool isGameFinished();
	void checkPlayerMovement();
	void doIntroBeeps(const float& dt);
	




};
#endif