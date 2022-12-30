#include "StartSign.h"

StartSign::StartSign(int screeny, int segmentId, float depth, bool left) : RoadObject(screeny, segmentId, depth, left)
{
	if (!texture.loadFromFile("assets/roadside/startsheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();
}

StartSign::StartSign(int segmentId, float depth, bool left):RoadObject(segmentId, depth, left)
{
	if (!texture.loadFromFile("assets/roadside/startsheet.png"))
		std::cout << "error loading assets" << '\n';

	loadSprites();

}

void StartSign::loadSprites()
{
	int ix = 0;
	int iy = 0;
	int sizes[4] = { 16,11,8,4 };
	for (int i = 0; i < sizeof(sprites) / sizeof(sprites[0]); i++)
	{
		sprites[i] = sf::Sprite(texture, sf::IntRect(ix, iy, sizes[i], 64));
		sprites[i].setPosition(sf::Vector2f((0.5 + perspective + Track::tile_w) * GameGlobals::GAME_W, screen_y - activeSpr->getGlobalBounds().height / 2));
		ix = sizes[0];
		iy -= 16;
		sprites[i].setOrigin(sf::Vector2f(sprites[i].getGlobalBounds().width / 2, 0));
	}

	//reassign default
	activeSpr = &sprites[3];
	base_transform = sprites[3].getTransform();
}
