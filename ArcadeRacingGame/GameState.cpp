#include "GameState.h"

GameState::GameState(TrackData trackdata) : State(),
track(trackdata.colors,trackdata.segments,trackdata.totalTrackLength), 
road_objects(trackdata.objects),
player(sf::Vector2f(GameGlobals::SCREEN_W / 2, (GameGlobals::GAME_H)-30)),
bg(),
ui()
{
	
	raceTimer = TIMER_START;
	intro = true;
	if (!b1_buf.loadFromFile("assets/sounds/beep1.wav") || !music_buf.loadFromFile("assets/sounds/music.wav"))
	{
		std::cout << "failed to load sounds";
	}
	beep_1.setBuffer(b1_buf);
	

}


void GameState::handleInput(sf::Event& e)
{

	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::W)
			moving = true;
		else if (e.key.code == sf::Keyboard::D)
			right = true;
		else if (e.key.code == sf::Keyboard::A)
			left = true;
	}
	if (e.type == sf::Event::KeyReleased)
	{
		if (e.key.code == sf::Keyboard::W)
			moving = false;
		else if (e.key.code == sf::Keyboard::D)
			right = false;
		else if (e.key.code == sf::Keyboard::A)
			left = false;
	}
	
}

//update all the elements in the state
void GameState::update(const float& dt)
{
	if (!intro)
	{
		checkPlayerMovement();
		decrementRaceTimer(dt);
		if (player.distanceToTrackEdge() > 400.0f)
		{
			Track::addAcceleration(-0.03f);
		}	
	}
	else
	{
		doIntroBeeps(dt);
	}
	track.update(dt);
	player.update(dt);
	bg.update(dt);
	for (RoadObject* r : road_objects)
		r->update(dt);
	sendVarsToUI();
	ui.update(dt);

	if (isGameFinished())
		exited = true;

}

void GameState::sendVarsToUI()
{
	ui.getRaceTimer(raceTimer);
}

void GameState::decrementRaceTimer(float dt)
{
	raceTimer = Racing::Util::clamp(raceTimer -= dt,0, TIMER_START);
}

bool GameState::isGameFinished()
{
	return raceTimer <= 0 || track.lapsDone == 3;
}

void GameState::checkPlayerMovement()
{
	if (moving)
		Track::addAcceleration(0.02);
	else
		Track::addAcceleration(-0.02);
	if (left)
		track.addPlayerOffset(0.02, true);
	if (right)
		track.addPlayerOffset(0.02, false);
}

void GameState::doIntroBeeps(const float& dt)
{
	
		beep_timer += dt;

		if (!beeps[0] && beep_timer >= 1.2f)
		{
			beep_1.play();
			beeps[0] = true;
		}
		else if (!beeps[1] && beep_timer >= 2.4f)
		{
			beep_1.play();
			beeps[1] = true;
		}	
		else if (!beeps[2] && beep_timer >= 3.6f)
		{
			beep_1.play();
			beeps[2] = true;
		}

		if (beeps[0] && beeps[1] && beeps[2] && beep_timer >= 4.8f)
		{
			intro = false;
			beep_1.setPitch(2);
			beep_1.play();
			
		}
	
}


//draw all the elements in the state to the rtx only
void GameState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear();

	track.drawElement(*renderer.rtx);
	player.drawElement(*renderer.rtx);
	bg.drawElement(*renderer.rtx);
	for (RoadObject* r : road_objects)
		r->drawElement(*renderer.rtx);
	ui.drawElement(*renderer.rtx);

	
	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2)); //scale using dimensions instead
	

}

int GameState::nextState()
{
	return raceTimer > 0 && track.lapsDone == 3 ? 0 : 1;
}

void GameState::quit()
{

}


