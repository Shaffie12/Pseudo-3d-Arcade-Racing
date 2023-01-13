#ifndef _TABLE_H_
#define _TABLE_H_
#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include "FontsManager.h"
#include "GameGlobals.h"
#include <map>

template <typename A, typename B>
class Table : public Drawable
{
	std::vector<std::pair<A,B>> tableData;
	sf::Text titleText;
public:
	Table(std::vector<std::pair<A,B>> data) :tableData(data) 
	{ 
		titleText.setString("TOP 10 RACERS"); 
		titleText.setFont(FontsManager::GetInstance()->font_basic);
		titleText.setPosition(sf::Vector2f(GameGlobals::GAME_W / 2 - titleText.getGlobalBounds().width / 2, GameGlobals::GAME_H / 2-130));
		titleText.setFillColor(sf::Color::White); 
		titleText.setScale(sf::Vector2f(1, 1));
	};
	Table()
	{
		titleText.setString("TOP 10 RACERS");
		titleText.setFont(FontsManager::GetInstance()->font_basic);
		titleText.setPosition(sf::Vector2f(GameGlobals::GAME_W / 2 - titleText.getGlobalBounds().width / 2, GameGlobals::GAME_H / 2-130));
		titleText.setFillColor(sf::Color::White);
		titleText.setScale(sf::Vector2f(1, 1));
	}
		
	void loadData(std::vector<std::pair<A,B>> data) { tableData = data; };
	void drawElement(sf::RenderTarget& w) override 
	{ 
		w.draw(titleText); 
		
	};
	void update(const float& dt) override {};

};
#endif

