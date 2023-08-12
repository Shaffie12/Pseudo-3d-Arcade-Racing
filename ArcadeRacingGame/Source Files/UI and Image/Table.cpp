#include "Table.h"



Table::Table(std::vector<std::pair<std::string, float>> data) :tableData(data)
{
}

Table::Table()
{
	int size = sizeof(headingsText) / sizeof(headingsText[0]);
	for (int i = 0; i <size; i++)
	{
		headingsText[i].setFont(FontsManager::GetInstance()->font_basic);
		headingsText[i].setFillColor(sf::Color::White);
		headingsText[i].setScale(0.7f, 0.7f);
	}

	headingsText[0].setString("RANK");
	headingsText[0].setPosition(sf::Vector2f( ((GameGlobals::GAME_W/2)/ (3 + 1) * 1 + 1)-headingsText[0].getGlobalBounds().width, (GameGlobals::GAME_H / 2 - 150)));
	headingsText[1].setString("NAME");
	headingsText[1].setPosition(sf::Vector2f(((GameGlobals::GAME_W/2) / (3 + 1) * 2 + 1)-headingsText[1].getGlobalBounds().width, (GameGlobals::GAME_H / 2 -150)));
	headingsText[2].setString("TIME");
	headingsText[2].setPosition(sf::Vector2f(((GameGlobals::GAME_W/2) / (3 + 1) * 3 + 1) - headingsText[2].getGlobalBounds().width, (GameGlobals::GAME_H / 2 - 150)));

	
}

void Table::loadData(std::vector<std::pair<std::string, float>> data) { tableData = data; setupTable();}

void Table::drawElement(sf::RenderTarget& w)
{
	for (sf::Text t : headingsText)
		w.draw(t);
	for (int i = 0; i < 10; i++)
	{
		w.draw(ranks[i]);
		w.draw(names[i]);
		w.draw(scores[i]);
	}
		
}

void Table::setupTable()
{
	std::stringstream s;
	for (int i = 1; i < 11; i++)
	{
		ranks[i - 1].setString(std::to_string(i));
		ranks[i - 1].setFont(FontsManager::GetInstance()->font_basic);
		ranks[i - 1].setFillColor(sf::Color::White);
		ranks[i - 1].setScale(0.5f, 0.5f);
		ranks[i - 1].setPosition(headingsText[0].getPosition().x, (GameGlobals::GAME_H / (10 + 1) * i + 1) + headingsText[0].getPosition().y);
	}

	for (int i = 0; i < 10; i++)
	{
		if (tableData.size() > i)
		{
			if (tableData.at(i).second > 0)
			{
				names[i].setString(tableData.at(i).first);
				names[i].setFont(FontsManager::GetInstance()->font_basic);
				names[i].setFillColor(sf::Color::White);
				names[i].setScale(0.5f, 0.5f);
				names[i].setPosition(sf::Vector2f((headingsText[1].getPosition().x), (GameGlobals::GAME_H / (10 + 1) * i + 1) + headingsText[1].getPosition().y + 30));
			}
			
		}
			
	}

	for (int i = 0; i < 10; i++)
	{
		if (tableData.size() > i)
		{
			if (tableData.at(i).second > 0)
			{
				s.str("");
				s <<std::setw(5)<< std::setfill('0')<<std::fixed<<std::setprecision(2) << tableData.at(i).second;
				scores[i].setString(s.str());
				scores[i].setFont(FontsManager::GetInstance()->font_basic);
				scores[i].setFillColor(sf::Color::White);
				scores[i].setScale(0.5f, 0.5f);
				scores[i].setPosition(sf::Vector2f(headingsText[2].getPosition().x, (GameGlobals::GAME_H / (10 + 1) * i + 1) + headingsText[2].getPosition().y + 30));
			}
			
		}
	}
}

void Table::update(const float& dt)
{
}
