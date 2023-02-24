#ifndef RACER_H_
#define RACER_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "ImageManager.h"
#include "Track.h"


class Racer :public Drawable
{
	public:
		Racer(Track& t, sf::Vector2f startPosition, sf::Color color = sf::Color::White);
		void drawElement(sf::RenderTarget& w) override;
		virtual float distanceToTrackEdge();
		virtual void update(const float& dt) override;
		void Destroy();
		bool isDead() { return dead; }
	protected:
		bool dead = false;
		sf::Sprite* activeSprite = nullptr;
		sf::Vector2f RacerPosition;
		std::vector<sf::Sprite> racerSprites;
		sf::Sprite explosions[3];
		int drawExplosionIdx = 0;
		Track& track;
		sf::Clock clock;
		virtual void OnDestroy();
		void loadSprites(sf::Vector2f startPosition, sf::Color color);		

};

#endif 
