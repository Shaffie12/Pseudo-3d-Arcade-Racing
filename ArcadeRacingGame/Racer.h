#ifndef RACER_H_
#define RACER_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Track.h"


class Racer :public Drawable
{
	public:
		Racer(sf::Vector2f startPosition);
		void drawElement(sf::RenderTarget& w) override;
		float distanceToTrackEdge();
		virtual void update(const float& dt) override;
		
		

	private:
		sf::Vector2f RacerPosition;
		sf::Texture racerTexture;
		std::vector<sf::Sprite> racerSprites;

};

#endif 
