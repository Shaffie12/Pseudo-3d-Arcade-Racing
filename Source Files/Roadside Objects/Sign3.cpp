#include "Sign3.h"

Sign3::Sign3(int screeny, int segmentId, float depth, bool left, Track& t) : RoadObject(screeny, segmentId, depth, left, t)
{
	if (!texture.loadFromFile("assets/roadside/sign3sheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}

Sign3::Sign3(int segmentId, float depth, bool left, Track& t) : RoadObject(segmentId, depth, left, t)
{
	if (!texture.loadFromFile("assets/roadside/sign3sheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}

void Sign3::loadSprites()
{
	int ix = 0;
	int iy = 0;
	int x = 32;
	int y = 25;
	int sizes[3] = { 6,12,19 };
	int yVals[4] = { 19,13,6 };
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
	{
		sprites[i] = sf::Sprite(texture, sf::IntRect(ix, iy, x, y));
		sprites[i].setPosition(sf::Vector2f((0.5 + perspective + Track::tile_w) * GameGlobals::GAME_W, screen_y - activeSpr->getGlobalBounds().height / 2));
		if (i < 3)
		{
			ix = x;
			iy = 0 + sizes[i];
			x -= 8;
			y = yVals[i];
		}
		
		sprites[i].setOrigin(sf::Vector2f(sprites[i].getGlobalBounds().width / 2, 0));
	}

	//reassign default
	activeSpr = &sprites[3];
	base_transform = sprites[3].getTransform();
}
