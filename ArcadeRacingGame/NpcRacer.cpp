#include "NpcRacer.h"


NpcRacer::NpcRacer(Track& t, sf::Vector2f startPos, sf::Color color) :Racer(t, startPos, color), baseSpeed(std::rand() % 10 + 8), currentSpeed(0), m_color(color),
moveInterval(float(std::rand()) / float((10000)))
{
	trackPos = (activeSprite->getPosition().y + activeSprite->getGlobalBounds().height / 2) - 150;
	clock.restart();
}

//scale the npc speed by how far up the screen it is, also add some speed if the player stops moving
void NpcRacer::update(const float& dt)
{
	generateNextOffset();
	position(dt);
	scale();
	recolorSprite();
}

const float NpcRacer::distanceFromCenter() const
{
	float screen_x = activeSprite->getPosition().x + activeSprite->getGlobalBounds().width / 2;
	return screen_x - track.lines.at(trackPos).middlePt * GameGlobals::GAME_W;
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
void NpcRacer::position(const float& dt)
{
	float currentSpeed = baseSpeed * Racing::Util::convertRange(trackPos, 0, 149, 0, 1) + (baseSpeed * 3) * (1 - track.acceleration);

	sf::Vector2f pos = activeSprite->getPosition();
	float newY = pos.y - currentSpeed * dt;
	pos.y = (newY + activeSprite->getGlobalBounds().height) - 150 < 0 ? GameGlobals::GAME_H/2 : newY;
	
	float positionScale = Racing::Util::clamp(Racing::Util::convertRange(pos.y-150, 0, 80, 0, 1), 0, 1);
	trackPos = (pos.y + activeSprite->getGlobalBounds().height / 2) - 150;
	if (trackPos < 90)
	{
		//float linePers = track.lines.at(trackPos).perspective;
		//float offset = ((linePers * GameGlobals::GAME_W) * nextOffset);
		activeSprite->setPosition(sf::Vector2f((pos.x - distanceFromCenter() * (1 - positionScale)), pos.y));
	}
	else
		activeSprite->setPosition(sf::Vector2f(pos.x - distanceFromCenter() * (0.02f), pos.y));

	
		
}

void NpcRacer::generateNextOffset()
{
	if (clock.getElapsedTime().asSeconds() >= moveInterval)
	{
		nextOffset = 0.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1.0f - 0.1f)));
		clock.restart();
	}
		
}
