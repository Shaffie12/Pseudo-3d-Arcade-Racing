#include "Background.h"
#include <iostream>

Background::Background()
{
	
	if (!bgTex.loadFromFile("assets/scenes.png"))
	{
		std::cout << "could not load background images" << '\n';

	}

	int startPix = 4;
	int ix = 260; //full image sizes
	int iy = 320; 
	int row = 0;

	
	int i = 0;
	int j = 0;
	while (i < 17)
	{
		int x = startPix + ((j * ix) % bgTex.getSize().x);
		if (x == 4 && i != 0)
			row++;	
		int y = 4 + (row * iy)+(row*4);
		
		bg_list.push_back(sf::Sprite(bgTex, sf::IntRect(x, y, ix - 4, iy - 64)));
		bg_list.at(i).setScale(2 , 0.588); //just calculate using the img dimensions of the screen keep aspect ratio same
		

		j = ++j % 3;
		i++;
	}
	//default
	selected_bg = &bg_list.at(0);
	gameBG = new ScrollingBackground(*selected_bg); 
	

}

void Background::setBackground(int bgNum) //just make it so the input for this in the menu cannot go above the size of the bg array
{
	
}

void Background::update(float deltaTime)
{
	scroll((-1 * Track::activeSeg->curvature) * Track::acceleration);
}

void Background::drawElement(sf::RenderTarget& w)
{
	
	for (ScrollingBackground::ImagePart& part : gameBG->imgs)
		if (part.onScreen())
			w.draw(part.sprite);

}

 void Background::scroll(float amount) 
 { 
	 
	 for (ScrollingBackground::ImagePart& part : gameBG->imgs)
	 {
		 part.sprite.setPosition(sf::Vector2f(std::floor(part.sprite.getPosition().x + (amount*1000)), 0));

		 if (part.sprite.getPosition().x < -2 * part.sprite.getGlobalBounds().width)
			 part.sprite.setPosition(sf::Vector2f(std::floor(part.sprite.getGlobalBounds().width-3), 0));
		 if (part.sprite.getPosition().x > 2 * part.sprite.getGlobalBounds().width)
			 part.sprite.setPosition(sf::Vector2f(-part.sprite.getGlobalBounds().width + 2, 0));
	 }
 }


