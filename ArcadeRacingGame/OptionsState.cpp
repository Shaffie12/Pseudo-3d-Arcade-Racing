#include "OptionsState.h"

OptionsState::OptionsState() : bars { 
	SlidingBar(sf::Vector2f(GameGlobals::GAME_W/2 +30,GameGlobals::GAME_H/2)), SlidingBar(sf::Vector2f(GameGlobals::GAME_W/2 + 30,GameGlobals::GAME_H/2 + 20)) },
	menu(GameGlobals::GAME_W,-250, 2, {"MUSIC VOLUME", "SFX VOLUME"}, sf::Color::White)
{
}

void OptionsState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Enter || e.key.code == sf::Keyboard::Space)
			quit();
		else if (e.key.code == sf::Keyboard::D)
			bars[selectedBar].Increase();
		else if (e.key.code == sf::Keyboard::A)
			bars[selectedBar].Decrease();
		else if (e.key.code == sf::Keyboard::W)
			menu.MoveUp();
		else if (e.key.code == sf::Keyboard::S)
			menu.MoveDown();		

	}
	
}

void OptionsState::update(const float& dt)
{
	menu.update(dt);
	for (SlidingBar b : bars)
		b.update(dt);
}

void OptionsState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(sf::Color::Black);
	menu.drawElement(*renderer.rtx);
	//for(SlidingBar b: bars)
		//b.drawElement(*renderer.rtx);
	
	renderer.rtx->display();
	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
}

void OptionsState::quit()
{
	exited = true;
}

int OptionsState::nextState()
{
	return -1;
}
