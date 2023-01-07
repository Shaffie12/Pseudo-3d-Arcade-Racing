#include "Background.h"
#include <iostream>

Background::Background(int bgNumber)
{
	if (bgNumber > ImageManager::GetInstance()->bg_list.size())
		bgNumber = ImageManager::GetInstance()->bg_list.size();

	selected_bg = &ImageManager::GetInstance()->bg_list.at(bgNumber);
	gameBG = new ScrollingBackground(*selected_bg); 
	

}

void Background::update(const float& dt)
{
	scroll((-1 * Track::activeSeg->curvature) * Track::acceleration );
}

void Background::drawElement(sf::RenderTarget& w)
{
	
	for (ScrollingBackground::ImagePart& part : gameBG->imgs)
		w.draw(part.sprite);
	

}

 void Background::scroll(float amount) 
 { 
	 
	 for (int i=0;i<gameBG->imgs.size();i++)
	 {
		 ScrollingBackground::ImagePart& part = gameBG->imgs.at(i);
		 part.sprite.setPosition(sf::Vector2f(std::floor(part.sprite.getPosition().x + (amount * 1000)), 0));

		 if (part.sprite.getPosition().x < -1.5f * part.sprite.getGlobalBounds().width)
		 {
			 part.sprite.setPosition(sf::Vector2f(gameBG->imgs.at(2-i).sprite.getPosition().x + (part.sprite.getGlobalBounds().width-10), 0));
			 ScrollingBackground::ImagePart temp = part;
			 gameBG->imgs.at(0) = gameBG->imgs.at(1);
			 gameBG->imgs.at(1) = gameBG->imgs.at(2);
			 gameBG->imgs.at(2) = temp;
			 
		 }
		 else if (part.sprite.getPosition().x  >= part.sprite.getGlobalBounds().width * 1.5f)
		 {
			 part.sprite.setPosition(sf::Vector2f(gameBG->imgs.at(2 - i).sprite.getPosition().x - part.sprite.getGlobalBounds().width, 0));

			 ScrollingBackground::ImagePart temp = part;
			 gameBG->imgs.at(2) = gameBG->imgs.at(1);
			 gameBG->imgs.at(1) = gameBG->imgs.at(0);
			 gameBG->imgs.at(0) = temp;
		 }
		 
		 

		 /*
		 part.sprite.setPosition(sf::Vector2f(std::floor(part.sprite.getPosition().x + (amount*GameGlobals::GAME_W)), 0));

		 if (part.sprite.getPosition().x < -2 * part.sprite.getGlobalBounds().width)
			 part.sprite.setPosition(sf::Vector2f(part.sprite.getGlobalBounds().width, 0));
		 if (part.sprite.getPosition().x > 2 * part.sprite.getGlobalBounds().width)
			 part.sprite.setPosition(sf::Vector2f(-part.sprite.getGlobalBounds().width + 2, 0));
			 */
	 }
 }


