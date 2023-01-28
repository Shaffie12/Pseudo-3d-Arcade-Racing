#ifndef _IMAGE_MANAGER_H_
#define _IMAGE_MANAGER_H_
#include <SFML/Graphics.hpp>
#include <iostream>

class ImageManager
{
private:
	ImageManager();
	~ImageManager();
	sf::Texture backgroundsTexture;
	

	static ImageManager* _imageManager;

	
public:
	ImageManager(const ImageManager& other) = delete;
	void operator=(const ImageManager&) = delete;

	static ImageManager* GetInstance();

	std::vector<sf::Sprite> bg_list;
	sf::Texture trophyTexture;
	sf::Texture deathTextures[3];
	sf::Sprite deathSprites[3];
	

	
};

#endif 
