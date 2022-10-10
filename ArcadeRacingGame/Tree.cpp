#include "Tree.h"
#include<iostream>

Tree::Tree(): RoadObject()
{
	screen_y = GameGlobals::GAME_H / 2 + 100;

	if (!texture.loadFromFile("assets/roadside/tree/treeRound1.png"))
		std::cout << "error loading assets" << '\n';
	sprite.setTexture(texture);
	//sprites.at(0).setPosition(sf::Vector2f(GameGlobals::GAME_W / 2, GameGlobals::GAME_H / 2 + 20));
	/*
	for (int i = 0; i < 4; i++)
	{
		textures.push_back(sf::Texture());
		int imgNum = i + 1;
		std::string num = std::to_string(imgNum);
		if (!(textures.at(i).loadFromFile("assets/roadside/tree/treeRound" + num + ".png")))
		{
			std::cout<<"could not load asset sprite"<<'\n';
		}
		sf::Sprite s(textures.at(i), sf::IntRect(0, 0, textures.at(i).getSize().x, textures.at(i).getSize().y));
		s.setPosition(sf::Vector2f(0.5 * GameGlobals::GAME_W + 20, screen_y)); //its position x depends on the width of the line at that point/perspective
		
		sprites.push_back(s);
	}
	*/
}

Tree::Tree(Tree&& other) noexcept
{
	texture = other.texture;
	sprite = other.sprite;
	sprite.setTexture(texture);
}





