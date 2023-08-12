#include "TextInput.h"

TextInput::TextInput()
{
	input << "___";
	input.seekp(0);
	text.setString(input.str());
	text.setFont(FontsManager::GetInstance()->font_basic);
	text.setFillColor(sf::Color::Black);
	text.setLetterSpacing(5);
	text.setPosition(sf::Vector2f(GameGlobals::GAME_W / 2 - text.getGlobalBounds().width/2, GameGlobals::GAME_H / 2 - 50 ));

}

void TextInput::update(const float& dt)
{
	blink += dt;
	sf::Color newCol = sinf(10 * blink) > 0 ? sf::Color::Transparent : sf::Color::Black;
	
	text.setFillColor(newCol);
}

void TextInput::drawElement(sf::RenderTarget& w)
{
	w.draw(text);
}

int TextInput::getBufSize()
{
	input.seekg(0, std::ios::end);
	return input.tellg();

}

void TextInput::handleInput(sf::Event& e)
{
	if (e.type == sf::Event::TextEntered )
	{
		if (input.tellp() < 3)
		{
			if ((e.text.unicode > 64 && e.text.unicode < 91) || (e.text.unicode > 96 && e.text.unicode < 123))
			{
				input << static_cast<char>(e.text.unicode);
				text.setString(input.str());
			}
		}
		if (e.text.unicode == 8)
		{
			if (input.tellp() > 0)
			{
				input.seekp(-1, std::ios::cur);
				input << '_';
				input.seekp(-1, std::ios::cur);
				text.setString(input.str());
			}
			

		}
	}
}


