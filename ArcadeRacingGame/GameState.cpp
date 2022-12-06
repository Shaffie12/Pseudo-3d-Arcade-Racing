#include "GameState.h"

GameState::GameState(TrackData trackdata) : State(),
track(trackdata.colors,trackdata.segments,trackdata.totalTrackLength), 
road_objects(trackdata.objects),
player(sf::Vector2f(GameGlobals::SCREEN_W / 2, (GameGlobals::GAME_H)-30)),
bg(),
ui()
{
	raceTimer = 80.0f;
	intro = true;
}

void GameState::handleInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		Track::addAcceleration(0.02);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			track.addPlayerOffset(0.02, true);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			track.addPlayerOffset(0.02, false);
	}
	else
		Track::addAcceleration(-0.02);

}

//update all the elements in the state
void GameState::update(const float& dt)
{
	decrementRaceTimer(dt);
	ui.getRaceTimer(raceTimer);
	if (player.distanceToTrackEdge() > 400.0f)
	{
		Track::addAcceleration(-0.03f);
	}
	

	track.update(dt);
	player.update(dt);
	bg.update(dt);
	ui.update(dt);
}

void GameState::decrementRaceTimer(float dt)
{
	raceTimer -= dt;
}


//draw all the elements in the state to the rtx only
void GameState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear();

	track.drawElement(*renderer.rtx);
	player.drawElement(*renderer.rtx);
	bg.drawElement(*renderer.rtx);
	for (RoadObject& r : road_objects)
		r.drawElement(*renderer.rtx);
	ui.drawElement(*renderer.rtx);

	
	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2)); //scale using dimensions instead
	

}

void GameState::quit()
{
}


