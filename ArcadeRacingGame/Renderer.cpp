#include "Renderer.h"
#include "GameGlobals.h"
#include <iostream>
#include "Util.h"

Renderer::Renderer() {}

void Renderer::draw(sf::RenderWindow& w, Drawable& d) { d.drawElement(w); }
