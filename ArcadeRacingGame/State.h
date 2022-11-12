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
	
	virtual void handleInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void drawToTexture(Renderer& renderer) = 0;
	virtual void quit() = 0;
};

#endif 
