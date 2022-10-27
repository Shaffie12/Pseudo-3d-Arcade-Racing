#include "Sign.h"
#include<iostream>

Sign::Sign(float depth, bool left): RoadObject(depth, left)
{
	if (!texture.loadFromFile("assets/roadside/signsheet.png"))
		std::cout << "error loading assets" << '\n';


	int ix = 0;
	int iy = 0;
	int size = 32;
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
	{
		sprites[i] = sf::Sprite(texture, sf::IntRect(ix, iy, size, size));
		sprites[i].setPosition(sf::Vector2f((0.5 + perspective+Track::tile_w) * GameGlobals::GAME_W, screen_y - activeSpr->getGlobalBounds().height / 2));
		ix += size;
		iy += 8;
		size -= 8;
	}
	
	//reassign default
	activeSpr = &sprites[3];
	original_dimensions = sf::Vector2f(sprites[3].getLocalBounds().width, sprites[3].getLocalBounds().height);
	
	
}






