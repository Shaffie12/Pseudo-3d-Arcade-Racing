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
		
		bgs.push_back(sf::Sprite(bgTex, sf::IntRect(x, y, ix - 4, iy - 64)));
		bgs.at(i).setScale(4, 1.17);
		
	
		j = ++j % 3;
		i++;
	}

	

	

}

void Props::drawElement(sf::RenderWindow& w)
{
	w.draw(bgs.at(8));
}