#include "OptionsState.h"

OptionsState::OptionsState(float sfxV, float musicV, bool useController) :
menu(GameGlobals::GAME_W/2-130,GameGlobals::GAME_H/2-8, 3, { "MUSIC VOLUME","SFX VOLUME", "USE CONTROLLER"}, sf::Color::White),
toggleElements { 
	new SlidingBar(sf::Vector2f(GameGlobals::GAME_W/2 +30 ,GameGlobals::GAME_H/2), sf::Color(255,0,0), sf::Color(255,128,0),musicV), 
	new SlidingBar(sf::Vector2f(GameGlobals::GAME_W/2 + 30,GameGlobals::GAME_H/2 + 30),sf::Color(255,0,0), sf::Color(255,128,0),sfxV),
	new YesNoOption(menu.GetElementPosition(2),useController)
}	
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
			toggleElements[menu.getSelected()]->Increase(menu.getSelected());
		else if (e.key.code == sf::Keyboard::A)
			toggleElements[menu.getSelected()]->Decrease(menu.getSelected());
		else if (e.key.code == sf::Keyboard::W)
			menu.MoveUp();
		else if (e.key.code == sf::Keyboard::S)
			menu.MoveDown();
	}
	
}

void OptionsState::update(const float& dt)
{
	menu.update(dt);
	for (UIElement* b : toggleElements)
		b->update(dt);
}

void OptionsState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(sf::Color::Black);

	menu.drawElement(*renderer.rtx);
	for(UIElement* b: toggleElements)
		b->drawElement(*renderer.rtx);

	renderer.sprite->setTexture(renderer.rtx->getTexture());
	renderer.sprite->setScale(sf::Vector2f(2, 2));
	renderer.rtx->display();

}

void OptionsState::quit()
{
	SettingsSaveData data;
	data.setMusicVolume(static_cast<SlidingBar*>(toggleElements[0])->GetValue());
	data.setSfxVolume(static_cast<SlidingBar*>(toggleElements[1])->GetValue());
	data.setController(static_cast<YesNoOption*>(toggleElements[2])->GetValue());
	data.WriteToFile();
	exited = true;
}

int OptionsState::nextState()
{
	return -1;
}
