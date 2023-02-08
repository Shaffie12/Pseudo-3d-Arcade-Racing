#include "Menu.h"




Menu::Menu(float width, float height, int numberOfElements, std::vector<std::string> menuItems, sf::Color color)
{
	elements = numberOfElements > MAX_ELEMENTS ? MAX_ELEMENTS : numberOfElements;

	for (int i = 0; i < elements; i++)
	{
		menuTexts[i].setString(menuItems.at(i));
		menuTexts[i].setFont(FontsManager::GetInstance()->font_basic);
		menuTexts[i].setFillColor(color);
		menuTexts[i].setPosition(sf::Vector2f(width / 2- menuTexts[i].getGlobalBounds().width/2, (height / (MAX_ELEMENTS + 1) * i + 1)+180));
		
	}
}

void Menu::MoveUp()
{
	SoundManager::GetInstance()->menuNavigate.play();
	menuTexts[selected].setFillColor(sf::Color::Black);
	selected -= 1;
	if (selected < 0)
		selected = elements-1;
	menuTexts[selected].setFillColor(sf::Color::Red);
	
}

void Menu::MoveDown()
{
	SoundManager::GetInstance()->menuNavigate.play();
	menuTexts[selected].setFillColor(sf::Color::Black);
	selected += 1;
	if (selected > elements - 1)
		selected = 0;
	menuTexts[selected].setFillColor(sf::Color::Red);
}

int Menu::getSelected()
{
	return selected;
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
	sf::Color newCol = sinf(10 * blink) > 0 ? sf::Color::Transparent : sf::Color::Black;
	menuTexts[selected].setFillColor(newCol);
}
