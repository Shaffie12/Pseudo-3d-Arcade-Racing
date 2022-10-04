#ifndef PROPS_H_
#define _PROPS_H_
#include "Drawable.h"
#include "GameGlobals.h"
#include "Track.h"
#include <memory>
#include<list>

class Props :public Drawable
{
public:
	Props();
	void drawElement(sf::RenderTarget& w);
	void scroll(float amount);
	void setBackground(int bgNum);

	//rather than using a static from the track to get the offset, we can maybe use a friend fn
private:
	sf::Texture bgTex; //dont know if we need to store this here
	std::vector<sf::Sprite> bg_list;
	sf::Sprite* selected_bg;

	class ScrollingBackground
	{
	public:
		
		ScrollingBackground(sf::Sprite& image) 
		{
			imgs.push_back(ImagePart(image, -image.getGlobalBounds().width, 0));
			imgs.push_back(ImagePart(image));
			imgs.push_back(ImagePart(image, image.getGlobalBounds().width, 0));
		}
			
		

		struct ImagePart
		{
			
			ImagePart(sf::Sprite& s)
			{
				sprite = s;
				sprite.setPosition(sf::Vector2f(0, 0));
			}
			ImagePart(sf::Sprite& s, float x, float y)
			{
				sprite = s;
				sprite.setPosition(sf::Vector2f(x, y));
			}

			sf::Sprite sprite;
			bool onScreen()
			{
				return !(sprite.getPosition().x > GameGlobals::GAME_W || sprite.getPosition().x + sprite.getGlobalBounds().width < 0);
			}

		};

		std::vector<ImagePart> imgs;
		

	};
	ScrollingBackground* gameBG;



};


#endif 
