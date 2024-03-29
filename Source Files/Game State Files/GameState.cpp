#include "GameState.h"

const int GameState::REQUIRED_LAPS = 3;

GameState::GameState(TrackData trackdata) : 
track(trackdata.colors,trackdata.segments,trackdata.totalTrackLength), 
roadObjectsContainer(trackdata.objects,track),
player(track, sf::Vector2f(GameGlobals::SCREEN_W / 2, (GameGlobals::GAME_H)-30)),
bg(track,0),
ui(track)
{
	srand(time(NULL));
	raceTimer = TIMER_START;
	intro = true;
	xMove = 0;
	yMove = 0;
	
	
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
	player.handleInput(e);
	if (GameGlobals::useController && GameGlobals::controller_connected)
	{
		float stick_x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
		float stick_y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);
		if (stick_x > 0)
		{
			right = true;
			left = false;
		}
		else if (stick_x < 0)
		{
			left = true;
			right = false;
		}
		if (stick_y > 0)
			moving = true;
		else if (stick_y < 0)
			moving = false;
		if (std::abs(stick_x/100.0f) < 0.1f)
			stick_x = 0.0f;
		yMove = Racing::Util::convertRange(Racing::Util::clamp(stick_y, 0.0f, 90.0f), 0.0f, 90.0f, 0.0f, 1.0f);
		xMove = std::abs(Racing::Util::convertRange(Racing::Util::clamp(stick_x, -80.0f, 80.0f), -80.0f, 80.0f, -1.0f, 1.0f));
		
			
	}
	else
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

		xMove = 1.0f;
		yMove = 1.0f;
	}
	

}

//update all the elements in the state
void GameState::update(const float& dt)
{
	if (!intro)
	{
		checkPlayerMovement(dt);
		if (SoundManager::GetInstance()->engine.getStatus() != sf::Sound::Status::Playing)
		{
			SoundManager::GetInstance()->engine.setPlayingOffset(sf::seconds(2));
			SoundManager::GetInstance()->engine.setLoop(true);
			SoundManager::GetInstance()->engine.play();
		}
		decrementRaceTimer(dt);
		for (NpcRacer* r : npcs)
		{
			r->update(dt);
			doCollisionDetection(r);
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
		track.addAcceleration(-0.13f * GameGlobals::FPS_MULTIPLIER* dt);
	}
	for (RoadObject* r : roadObjectsContainer.objects)
	{
		r->update(dt);
		doColiisionDetection(r);
	}
	track.update(dt);
	SoundManager::GetInstance()->engine.setPitch(track.getAcceleration());
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
	if ((r->screen_y >= GameGlobals::GAME_H - 50 && r->screen_y <= GameGlobals::GAME_H) && player.distanceFromCenter() <= -390 && r->left || 
		(r->screen_y  >= GameGlobals::GAME_H - 50 && r->screen_y <= GameGlobals::GAME_H) && player.distanceFromCenter() >= 390 && !r->left)
	{
		if (track.getAcceleration() <= 0.4f)
			track.addAcceleration(-track.getAcceleration());
		else
			if (!player.isDead())
				player.Destroy();
				
	}
					
}

void GameState::doCollisionDetection(NpcRacer*& r)
{
	
	bool closeX = std::abs(r->distanceFromCenter() - player.distanceFromCenter()) <= player.getSpriteSize().width;
	bool closeY = r->getSpritePosition().y >= 260 && r->getSpritePosition().y < 280;
	if (closeX && closeY)
	{
		if (track.getAcceleration() <= 0.4f)
			track.addAcceleration(-track.getAcceleration());
		else
		{
			if (!player.isDead())
				player.Destroy();
			if (!r->isDead())
				r->Destroy();
		}
			
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

void GameState::checkPlayerMovement(const float& dt)
{
	if (!player.isDead() && moving)
		track.addAcceleration(yMove* 0.1f* GameGlobals::FPS_MULTIPLIER * dt);
	else
		track.addAcceleration(-0.1f * GameGlobals::FPS_MULTIPLIER * dt);
	if (!player.isDead() && left)
		track.addPlayerOffset(xMove*0.025f* GameGlobals::FPS_MULTIPLIER * dt);
	if (!player.isDead() && right)
		track.addPlayerOffset(-xMove*0.025f* GameGlobals::FPS_MULTIPLIER * dt);
}

void GameState::doIntroBeeps(const float& dt)
{
		beep_timer += dt;
		if (!beeps[0] && beep_timer >= 1.0f)
		{
			SoundManager::GetInstance()->beep_1.play();
			beeps[0] = true;
		}
		else if (!beeps[1] && beep_timer >= 2.0f)
		{
			SoundManager::GetInstance()->beep_1.play();
			beeps[1] = true;
		}	
		else if (!beeps[2] && beep_timer >= 3.0f)
		{
			SoundManager::GetInstance()->beep_1.play();
			beeps[2] = true;
		}

		if (beeps[0] && beeps[1] && beeps[2] && beep_timer >= 4.0f)
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
	for (NpcRacer* r : npcs)
		r->drawElement(*renderer.rtx);
	bg.drawElement(*renderer.rtx);
	for (RoadObject* r : roadObjectsContainer.objects)
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
	SoundManager::GetInstance()->engine.stop();
	SoundManager::GetInstance()->engine.setPitch(1);
	exited = true;
	
}


