#include "Renderer.h"

Renderer::Renderer() {}

void Renderer::draw(sf::RenderWindow& w, Drawable& d) { d.drawElement(w); }
