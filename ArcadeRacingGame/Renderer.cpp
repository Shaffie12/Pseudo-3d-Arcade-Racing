#include "Renderer.h"
#include<iostream>
Renderer::Renderer() { rtx = new sf::RenderTexture; sprite = new sf::Sprite; }
Renderer::Renderer(const Renderer& other)
{
	//shallow
	sprite = other.sprite;
	rtx = other.rtx;
}
Renderer::~Renderer() { delete rtx; delete sprite;}
//why heap?
void Renderer::init()
{
	rtx->create(GameGlobals::GAME_W,GameGlobals::GAME_H);
	sprite->setTexture(rtx->getTexture());
	sprite->setTextureRect(sf::IntRect(0, 0, GameGlobals::GAME_W, GameGlobals::GAME_H));
}


