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

	void handleInput(const float& dt) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	void quit() override;

private:
	Track track;
	Player player;
	Background bg;
	UI ui;
	std::vector<RoadObject> road_objects;




};
#endif