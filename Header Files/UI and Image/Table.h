#ifndef _TABLE_H_
#define _TABLE_H_
#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include "FontsManager.h"
#include "GameGlobals.h"
#include <map>
#include <sstream>
#include <iomanip>


class Table : public Drawable
{
	std::vector<std::pair<std::string,float>> tableData;
	sf::Text headingsText[3];
	sf::Text ranks[10];
	sf::Text names[10];
	sf::Text scores[10];
	void setupTable();
public:
	Table(std::vector<std::pair<std::string, float>> data);
	Table();
	void loadData(std::vector<std::pair<std::string, float>> data);
	void drawElement(sf::RenderTarget& w) override;
	void update(const float& dt) override;

};
#endif

