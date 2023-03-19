#include "NpcRacer.h"


NpcRacer::NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color) :Racer(t, startPos, color), baseSpeed(std::rand() % 8 + 15), currentSpeed(0), m_color(color),
moveInterval(2.0f)
{
	speed = baseSpeed;
	trackPos = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - GameGlobals::GAME_H/2;
	x_clock.restart();
	y_clock.restart();
}

//scale the npc speed by how far up the screen it is, also add some speed if the player stops moving
void NpcRacer::update(const float& dt)
{
	
	canSlowDown = track.getAcceleration() >= 1.0f;
	generateNextOffset();
	setSpeed();
	if (!dead)
	{
		
		changeSpeed();
		position(dt);
	}
	else
	{
		OnDestroy();
		sf::Vector2f center(activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2, activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2);
		explosions[drawExplosionIdx].setPosition(
			sf::Vector2f(center.x - explosions[drawExplosionIdx].getGlobalBounds().width / 2, center.y - explosions[drawExplosionIdx].getGlobalBounds().height + 17));
	
	}

	
	scale();
	recolorSprite();
}

const float NpcRacer::distanceFromCenter() const
{
	float x = activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2;
	if(trackPos < 149)
		return x - track.lines.at(trackPos).middlePt * GameGlobals::GAME_W;
	return track.lines.at(track.lines.size()-1).middlePt * GameGlobals::GAME_W;
}

void NpcRacer::recolorSprite()
{
	if (trackPos == 0)
		activeSprite->setColor(sf::Color::Transparent);
	else
		activeSprite->setColor(m_color);
}

//non linearly scale the sprite as it moves up the track
void NpcRacer::scale() 
{
	int y = trackPos;
	float scale = Racing::Util::clamp(Racing::Util::roundToDP(Racing::Util::convertRange(sqrt(y), 0, sqrt(149), 0.1f, 2), 1),0.1,2);
	
	activeSprite->setScale(scale, scale);
}

//position the car on the road with x,y position
//convert to track coordinates and check if we can move forward or not
//scale the x and y movement speed based on how far up the track we are
//add a random offset sometimes
void NpcRacer::position(const float& dt)
{
	//y positioning
	sf::Vector2f pos = activeSprite->getPosition(); //300 to 150 upward
	
	//y positioning
	float newY = pos.y - currentSpeed * dt;
	pos.y = (newY + activeSprite->getGlobalBounds().height) - 150 < 0 ? GameGlobals::GAME_H +10000 : newY;
	
	//x positioning
	float positionScale = Racing::Util::clamp(Racing::Util::convertRange(pos.y - GameGlobals::GAME_H/2, 0, 90, 0.65f, 1), 0, 1);
	trackPos = (pos.y + activeSprite->getGlobalBounds().height / 2) - GameGlobals::GAME_H/2;

	//position sprite
	if (trackPos < 90)
		activeSprite->setPosition(sf::Vector2f((pos.x - (distanceFromCenter() + nextOffset) * (1 - positionScale)), pos.y));
	else
		activeSprite->setPosition(sf::Vector2f(pos.x - distanceFromCenter() * (0.02f), pos.y));
	
}

void NpcRacer::generateNextOffset()
{
	if (x_clock.getElapsedTime().asSeconds() >= moveInterval)
	{
		nextOffset = -20.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (20.0f - -20.0f)));
		x_clock.restart();
	}
		
}

void NpcRacer::setSpeed()
{
	if(!dead)
		currentSpeed = speed * Racing::Util::convertRange(trackPos, 0, 149, 0, 1) + (speed * 3) * (1 - track.getAcceleration());
	else
		currentSpeed = -baseSpeed * Racing::Util::convertRange(trackPos, 0, 149, 0, 1) + (speed * 3) *  track.getAcceleration();
}

void NpcRacer::changeSpeed()
{
	if (canSlowDown)
	{
		if (y_clock.getElapsedTime().asSeconds() > 10.0f)
		{
			y_clock.restart();
			speed = std::rand() % 30 - 15;
		}
	}
	else
		speed = baseSpeed;
	
}



