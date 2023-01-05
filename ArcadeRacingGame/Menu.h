#ifndef _MENU_H_
#define _MENU_H_
#include "Drawable.h"
#include "FontsManager.h"

constexpr int MAX_ELEMENTS = 5;

class Menu : public Drawable
{

private:
	int selected = 0;

public:

	Menu(float width, float height, int numberOfElements);
	void drawElement(sf::RenderTarget& w) override;
	void update(const float& dt) override;
	void MoveUp();
	void MoveDown();
	void setElementText(int element);
	sf::Text menuTexts[MAX_ELEMENTS];


};
#endif

