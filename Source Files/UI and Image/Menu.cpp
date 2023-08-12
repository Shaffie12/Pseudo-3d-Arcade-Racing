#include "Menu.h"

Menu::Menu(float width, float height, int numberOfElements, std::vector<std::string> menuItems, sf::Color color)
{
	elements = numberOfElements > MAX_ELEMENTS ? MAX_ELEMENTS : numberOfElements;
	this->color = color;
	for (int i = 0; i < elements; i++)
	{
		menuTexts[i].setString(menuItems.at(i));
		menuTexts[i].setFont(FontsManager::GetInstance()->font_basic);
		menuTexts[i].setFillColor(color);
		menuTexts[i].setPosition(sf::Vector2f(width - menuTexts[i].getGlobalBounds().width/2, (height + (i* yPadding) ) ));
		
	}
}

void Menu::MoveUp()
{
	SoundManager::GetInstance()->menuNavigate.play();
	menuTexts[selected].setFillColor(color);
	selected -= 1;
	if (selected < 0)
		selected = elements-1;
}

void Menu::MoveDown()
{
	SoundManager::GetInstance()->menuNavigate.play();
	menuTexts[selected].setFillColor(color);
	selected += 1;
	if (selected > elements - 1)
		selected = 0;
	
	
}

int Menu::getSelected()
{
	return selected;
}

void Menu::SetTextScale(float x, float y)
{
	for (sf::Text& t : menuTexts)
		t.setScale(x, y);
}

int Menu::getNumberOfElements()
{
	return elements;
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
	blink += dt;
	sf::Color newCol = sinf(10 * blink) > 0 ? sf::Color::Transparent : color;
	menuTexts[selected].setFillColor(newCol);
}
