#ifndef UI_ELEMENT_H_
#define UI_ELEMENT_H_

class UIElement : Drawable
{
public:
	virtual void Increase(int menuChoice) = 0;
	virtual void Decrease(int menuChoice) = 0;
	virtual void drawElement(sf::RenderTarget& w) override = 0;
	virtual void update(const float& dt)override  = 0;

};



#endif