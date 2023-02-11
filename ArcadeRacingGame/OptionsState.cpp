#include "OptionsState.h"

OptionsState::OptionsState(float sfxV, float musicV) : bars { 
	SlidingBar(sf::Vector2f(GameGlobals::GAME_W/2 +30 ,GameGlobals::GAME_H/2), sf::Color(255,0,0), sf::Color(255,128,0),musicV), 
	SlidingBar(sf::Vector2f(GameGlobals::GAME_W/2 + 30,GameGlobals::GAME_H/2 + 30),sf::Color(255,0,0), sf::Color(255,128,0),sfxV) },
	menu(GameGlobals::GAME_W/2-130,GameGlobals::GAME_H/2-8, 2, { "MUSIC VOLUME","SFX VOLUME" }, sf::Color::White)
{
	menu.SetTextScale(0.7f, 0.7f);
}

void OptionsState::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Enter || e.key.code == sf::Keyboard::Space)
			quit();
		else if (e.key.code == sf::Keyboard::D)
			bars[menu.getSelected()].Increase(menu.getSelected());
		else if (e.key.code == sf::Keyboard::A)
			bars[menu.getSelected()].Decrease(menu.getSelected());
		else if (e.key.code == sf::Keyboard::W)
			menu.MoveUp();
		else if (e.key.code == sf::Keyboard::S)
			menu.MoveDown();
	}
	
}

void OptionsState::update(const float& dt)
{
	menu.update(dt);
	for (SlidingBar& b : bars)
		b.update(dt);
}

void OptionsState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(sf::Color::Black);

	menu.drawElement(*renderer.rtx);
	for(SlidingBar b: bars)
		b.drawElement(*renderer.rtx);

	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
	renderer.rtx->display();

}

void OptionsState::quit()
{
	SettingsSaveData data;
	data.setMusicVolume(bars[0].GetValue());
	data.setSfxVolume(bars[1].GetValue());
	data.WriteToFile();
	exited = true;
}

int OptionsState::nextState()
{
	return -1;
}
