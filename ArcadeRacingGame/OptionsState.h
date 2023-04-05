#ifndef _OPTIONS_STATE_H_
#define _OPTIONS_STATE_H_
#include "State.h"
#include "Util.h"
#include "UIElement.h"
#include "Menu.h"
#include "FontsManager.h"
#include "SoundManager.h"
#include "SettingsSaveData.h"
#include<iostream>

class OptionsState: public State
{
public:
	OptionsState(float sfxV, float musicV, bool useController);
	~OptionsState()
	{
		for (UIElement* e : toggleElements)
			delete e;
	}
	void handleInput(sf::Event& e) override;
	void update(const float& dt) override;
	void drawToTexture(Renderer& renderer) override;
	void quit() override;
	int nextState() override;

private:
	struct SlidingBar : UIElement
	{
		SlidingBar(sf::Vector2f screenPos,sf::Color color1 = sf::Color::White, sf::Color color2 = sf::Color::White, float val = 1.0f) : value(val)
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
		void Increase(int menuChoice) override 
		{ 
			value = Racing::Util::clamp(value + 0.1f, 0.0f, 1.0f);
			if (menuChoice == 0)
				AdjustMusicVol();
			else
				AdjustSFXVol();	
		}
		void Decrease(int menuChoice)override  
		{
			value = Racing::Util::clamp(value - 0.1f, 0.0f, 1.0f); 
			if (menuChoice == 0)
				AdjustMusicVol();
			else
				AdjustSFXVol();
		}
		void SetValue(float val)  
		{
			value = Racing::Util::clamp(val, 0.0f, 1.0f); 
		}
		float& GetValue() { return value; }
	private:
		sf::Vertex barLines[10][2];
		const float MAX_LINE_SIZE = 100.0f;
		const float MIN_LINE_SIZE = 0.0f;
		float value;

		void AdjustMusicVol()
		{
			SoundManager::GetInstance()->music1.setVolume(value * 100.0f);
		}
		void AdjustSFXVol()
		{
			SoundManager::GetInstance()->menuNavigate.setVolume(value*100.0f);
			SoundManager::GetInstance()->menuSelect.setVolume(value * 100.0f);
			SoundManager::GetInstance()->beep_1.setVolume(value * 100.0f);
			SoundManager::GetInstance()->checkpoint.setVolume(value * 100.0f);
			SoundManager::GetInstance()->explosion.setVolume(value * 100.0f);
		}
	};
	struct YesNoOption : UIElement
	{
		YesNoOption(sf::Vector2f position, bool val = false)
		{
			
			yes.setString("YES");
			yes.setFont(FontsManager::GetInstance()->font_basic);
			yes.setScale(0.7f, 0.7f);
			yes.setFillColor(sf::Color::White);
			yes.setPosition(position);
			yes.setPosition(sf::Vector2f(GameGlobals::GAME_W / 2 + 30, position.y)); no.setPosition(sf::Vector2f(GameGlobals::GAME_W / 2 + 30, position.y));

			no.setString("NO");
			no.setFont(FontsManager::GetInstance()->font_basic);
			no.setScale(0.7f, 0.7f);
			no.setFillColor(sf::Color::White);
			no.setPosition(sf::Vector2f(GameGlobals::GAME_W/2 + 100, position.y));
			value = val;
		}

		void update(const float& dt) override 
		{
			if (value == true)
			{
				yes.setFillColor(sf::Color::Green);
				no.setFillColor(sf::Color::White);
			}
			else
			{
				yes.setFillColor(sf::Color::White);
				no.setFillColor(sf::Color::Green);
			}	
		}
		void drawElement(sf::RenderTarget& w) override 
		{ 
			w.draw(yes);
			w.draw(no);
		}
		void Increase(int menuChoice) override { value = false; AdjustGlobalControls(); }
		void Decrease(int menuChoice) override { value = true; AdjustGlobalControls(); }
		void SetValue(bool val) { value = val; }
		void AdjustGlobalControls() { GameGlobals::useController = value; }
		bool& GetValue() { return value; }

	private:
		bool value;
		sf::Text yes;
		sf::Text no;
	};
	Menu menu;
	UIElement* toggleElements [3];
	int selectedBar = 0;

};

#endif 
