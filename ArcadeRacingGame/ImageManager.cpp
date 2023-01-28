#include "ImageManager.h"

ImageManager* ImageManager::_imageManager = nullptr;

ImageManager::ImageManager()
{

	if (!backgroundsTexture.loadFromFile("assets/scenes.png") || !trophyTexture.loadFromFile("assets/trophy.png")||
		!deathTextures[0].loadFromFile("assets/death1.png") || !deathTextures[1].loadFromFile("assets/death2.png")|| !deathTextures[2].loadFromFile("assets/death3.png"))
	{
		std::cout << "could not load images" << '\n';

	}

	int startPix = 4;
	int ix = 260; //full image sizes
	int iy = 320;
	int row = 0;


	int i = 0;
	int j = 0;
	while (i < 17)
	{
		int x = startPix + ((j * ix) % backgroundsTexture.getSize().x);
		if (x == 4 && i != 0)
			row++;
		int y = 4 + (row * iy) + (row * 4);

		bg_list.push_back(sf::Sprite(backgroundsTexture, sf::IntRect(x, y, ix - 4, iy - 64)));
		bg_list.at(i).setScale(2, 0.588); //just calculate using the img dimensions of the screen keep aspect ratio same


		j = ++j % 3;
		i++;
	}

}

ImageManager::~ImageManager()
{
	delete _imageManager;
}

ImageManager* ImageManager::GetInstance()
{
	if (_imageManager == nullptr)
		_imageManager = new ImageManager();
	return _imageManager;
}