#ifndef _OPTIONS_STATE_H_
#define _OPTIONS_STATE_H_
#include "State.h"
#include "Util.h"
#include "Menu.h"
#include "FontsManager.h"
#include <iostream>

class OptionsState: public State
{
public:
	OptionsState();
	void handleInput(sf::Event& e) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	void quit() override;
	int nextState() override;

private:
	struct SlidingBar : Drawable
	{
		SlidingBar(sf::Vector2f screenPos,sf::Color color1 = sf::Color::White, sf::Color color2 = sf::Color::White) : value(1.0f)
		{
			for (int i = 0; i < sizeof(barLines)/sizeof(barLines[0]); i++) //factor in screen pos
			{
				sf::Vertex v1, v2;
				if (i < 5)
				{
					v1 = sf::Vector2f(screenPos.x, screenPos.y + i);
					v2 = sf::Vector2f(screenPos.x + value * MAX_LINE_SIZE + i, screenPos.y +i);
				}
				else
				{
					v1 = sf::Vector2f(screenPos.x, screenPos.y +i);
					v2 = sf::Vector2f(screenPos.x + value * MAX_LINE_SIZE + (sizeof(barLines)/sizeof(barLines[0])-i),screenPos.y +i);
				}
				
				v1.color = color1;
				v2.color = color2;

				barLines[i][0] =v1;
				barLines[i][1] = v2;
	
			}
		}

		void update(const float& dt) override
		{
			for (int i = 0; i < sizeof(barLines) / sizeof(barLines[0]); i++)
			{
				if (i < 5)
					barLines[i][1].position.x = barLines[i][0].position.x + (value * MAX_LINE_SIZE) + i;
				else
					barLines[i][1].position.x = barLines[i][0].position.x + (value * MAX_LINE_SIZE) + (sizeof(barLines) / sizeof(barLines[0]) - i);
			}

		}
		void drawElement(sf::RenderTarget& w) override
		{
			for (int i = 0; i < sizeof(barLines) / sizeof(barLines[0]); i++)
				w.draw(barLines[i], 2, sf::Lines);
		}

		void Increase() { value = Racing::Util::clamp(value + 0.1f, 0.0f, 1.0f); }
		void Decrease() { value = Racing::Util::clamp(value - 0.1f, 0.0f, 1.0f); }
		void SetValue(float val) { value = Racing::Util::clamp(val, 0.0f, 1.0f); }


	private:
		sf::Vertex barLines[10][2];
		const float MAX_LINE_SIZE = 100.0f;
		const float MIN_LINE_SIZE = 0.0f;
		float value;
	};
	Menu menu;
	SlidingBar bars [2];
	int selectedBar = 0;

};

#endif 
