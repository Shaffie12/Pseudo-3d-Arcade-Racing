#include "Props.h"
#include <iostream>

Props::Props()
{
	bgTex.loadFromFile("assets/scenes.png");
	int startPix = 4;
	int ix = 260; //full
	int iy = 320; //full size
	int row = 0;

	
	int i = 0;
	int j = 0;
	while (i < 17)
	{
		int x = startPix + ((j * ix) % bgTex.getSize().x);
		if (x == 4 && i != 0)
			row++;	
		int y = 4 + (row * iy)+(row*4);
		
		allBgs.push_back(sf::Sprite(bgTex, sf::IntRect(x, y, ix - 4, iy - 64)));
		allBgs.at(i).setScale(2 , 0.588); //just calculate using the img dimensions
		bg.push_back(allBgs.at(i));
		bg.push_back(allBgs.at(i));
		bg.push_back(allBgs.at(i));

		j = ++j % 3;
		i++;
	}


}

void Props::drawElement(sf::RenderTarget& w)
{
	w.draw(bg.at(0));
	bg.at(1).setPosition(bg.at(0).getPosition() + sf::Vector2f(bg.at(0).getGlobalBounds().width, 0));
	w.draw(bg.at(1)); //we actually want a copy here even if we do use pointers as well
	
}

 void Props::scroll(float amount) { 
	bg.at(0).setPosition(bg.at(0).getPosition() + sf::Vector2f(amount,0));

}