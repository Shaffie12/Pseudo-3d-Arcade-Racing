#ifndef _STATE_H_
#define _STATE_H_
#include <stack>
#include <map>
#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Renderer.h"

class State
{
public:
	bool exited = false;
	virtual void handleInput(sf::Event& e) = 0;
	virtual void update(const float& dt) = 0;
	virtual void drawToTexture(Renderer& renderer) = 0;
	virtual void quit() = 0;
	virtual int nextState() = 0;
};

#endif 
