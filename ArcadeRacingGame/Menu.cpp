#include "Menu.h"
#include <iostream>



Menu::Menu(float width, float height, int numberOfElements)
{
	int elements = 0;
	elements = numberOfElements > MAX_ELEMENTS ? MAX_ELEMENTS : numberOfElements;

	for (int i = 0; i < elements; i++)
	{
		menuTexts[i].setString("item " + i);
		menuTexts[i].setFont(FontsManager::GetInstance()->font);
		menuTexts[i].setFillColor(sf::Color::Black);
		menuTexts[i].setPosition(sf::Vector2f(width / 2, height / (MAX_ELEMENTS + 1) * i + 1));
		
	}

	//set default selected 
	menuTexts[0].setFillColor(sf::Color::Red);
}

void Menu::MoveUp()
{
}

void Menu::MoveDown()
{
}

void Menu::setElementText(int element)
{
}

void Menu::drawElement(sf::RenderTarget& w)
{
	for (sf::Text& text : menuTexts)
	{
		w.draw(text);
	}
}

void Menu::update(const float& dt)
{
}
