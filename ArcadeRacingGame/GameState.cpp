#include "GameState.h"

const int GameState::REQUIRED_LAPS = 3;

GameState::GameState(TrackData trackdata) : 
track(trackdata.colors,trackdata.segments,trackdata.totalTrackLength), 
roadObjectsContainer(trackdata.objects,track),
player(track, sf::Vector2f(GameGlobals::SCREEN_W / 2, (GameGlobals::GAME_H)-30)),
bg(track,0),
ui(track)
{
	raceTimer = TIMER_START;
	intro = true;
	
	
	npcs.push_back(new NpcRacer(track, sf::Vector2f((GameGlobals::GAME_W / 2) - 80, (GameGlobals::GAME_H)-10), sf::Color::Green));
	npcs.push_back(new NpcRacer(track, sf::Vector2f((GameGlobals::GAME_W / 2) + 80, (GameGlobals::GAME_H)-5), sf::Color::Red));

}

GameState::GameState(TrackData trackdata, std::string username): 
track(trackdata.colors, trackdata.segments, trackdata.totalTrackLength),
roadObjectsContainer(trackdata.objects,track),
player(track, sf::Vector2f(GameGlobals::SCREEN_W / 2, (GameGlobals::GAME_H)-30)),
bg(track, 0),
ui(track)
{
	this->username = username;
	raceTimer = TIMER_START;
	intro = true;
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
		for (NpcRacer* r : npcs)
		{
			r->update(dt);
		}
		std::sort(npcs.begin(), npcs.end(), [](NpcRacer*& a, NpcRacer*& b) {return *a < *b; });
	}
	else
	{
		doIntroBeeps(dt);
	}
	
	player.update(dt);
	if (player.distanceFromCenter() > 400.0f)
	{
		track.addAcceleration(-0.03f);
	}
	for (RoadObject* r : roadObjectsContainer.objects)
	{
		r->update(dt);
		doColiisionDetection(r);
	}
	track.update(dt);
	bg.update(dt);

	sendVarsToUI();
	ui.update(dt);
	if (laps != track.lapsDone)
	{
		SoundManager::GetInstance()->checkpoint.play();
		laps++;
		if(laps!=REQUIRED_LAPS)
			incrementRaceTimer(8);
	}
	if (isGameFinished())
		quit();

}

void GameState::doColiisionDetection(RoadObject*& r)
{
	
	if ((r->screen_y >= GameGlobals::GAME_H - 50 && r->screen_y <= GameGlobals::GAME_H) && player.distanceFromCenter() >= 390 && r->left || 
		(r->screen_y >= GameGlobals::GAME_H - 50 && r->screen_y <= GameGlobals::GAME_H) && player.distanceFromCenter() <= -390 && !r->left)
	{
		if (track.getAcceleration() <= 0.4f)
			track.addAcceleration(-track.getAcceleration());
		else
			if (!player.isDead())
				player.Destroy();
	}
					
}

void GameState::sendVarsToUI()
{
	ui.getRaceTimer(raceTimer);
}

void GameState::decrementRaceTimer(float dt)
{
	raceTimer = Racing::Util::clamp(raceTimer -= dt,0, TIMER_START);
}

void GameState::incrementRaceTimer(float amount)
{
	raceTimer += amount;
}

bool GameState::isGameFinished()
{
	return raceTimer <= 0 || track.lapsDone == REQUIRED_LAPS;
}

void GameState::checkPlayerMovement()
{
	if (!player.isDead() && moving)
		track.addAcceleration(0.02);
	else
		track.addAcceleration(-0.02); //instead of just taking away we need to take into consideration if the player is trying to move and allow them to eventually get enough force
	if (!player.isDead() && left)
		track.addPlayerOffset(0.02, true);
	if (!player.isDead() && right)
		track.addPlayerOffset(0.02, false);
}

void GameState::doIntroBeeps(const float& dt)
{
	
		beep_timer += dt;

		if (!beeps[0] && beep_timer >= 1.2f)
		{
			SoundManager::GetInstance()->beep_1.play();
			beeps[0] = true;
		}
		else if (!beeps[1] && beep_timer >= 2.4f)
		{
			SoundManager::GetInstance()->beep_1.play();
			beeps[1] = true;
		}	
		else if (!beeps[2] && beep_timer >= 3.6f)
		{
			SoundManager::GetInstance()->beep_1.play();
			beeps[2] = true;
		}

		if (beeps[0] && beeps[1] && beeps[2] && beep_timer >= 4.8f)
		{
			intro = false;
			SoundManager::GetInstance()->beep_1.setPitch(2);
			SoundManager::GetInstance()->beep_1.play();
			
			
		}
	
}

void GameState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear();

	track.drawElement(*renderer.rtx);
	
	bg.drawElement(*renderer.rtx);
	for (RoadObject* r : roadObjectsContainer.objects)
		r->drawElement(*renderer.rtx);
	for (NpcRacer* r : npcs)
		r->drawElement(*renderer.rtx);
		
	ui.drawElement(*renderer.rtx);
	player.drawElement(*renderer.rtx);
	
	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2)); //scale using dimensions instead
	}

int GameState::nextState()
{
	return raceTimer > 0 && track.lapsDone == REQUIRED_LAPS ? 1 : 2;
}

void GameState::quit()
{
	SoundManager::GetInstance()->beep_1.setPitch(1);
	exited = true;
	
}


