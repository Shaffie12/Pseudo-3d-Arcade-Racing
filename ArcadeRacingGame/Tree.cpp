#include "Tree.h"
#include<iostream>

Tree::Tree(float spawnDist): RoadObject(spawnDist)
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
	
	//default
	activeSpr = &sprites[3];
	


	/*

	for (int i = 3; i > -1; i-- )
	{
		std::cout << i << '\n';
		int imgNum = i + 1;
		std::string num = std::to_string(imgNum);
		if (!(textures[3-i].loadFromFile("assets/roadside/tree/treeRound" + num + ".png")))
			std::cout<<"could not load asset sprite"<<'\n';
		
		sf::Sprite s(textures[3-i], sf::IntRect(0, 0, textures[3-i].getSize().x, textures[3-i].getSize().y));
		
		s.setPosition(sf::Vector2f((0.6 + perspective) *GameGlobals::GAME_W, screen_y-s.getGlobalBounds().height/2 )); 
		
		
		sprites[3-i] = s; 

		
	}

	*/

	
	
}






