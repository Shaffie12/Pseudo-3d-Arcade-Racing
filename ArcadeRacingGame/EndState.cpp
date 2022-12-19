#include "GameOverState.h"

GameOverState::GameOverState()
{
	endScreenText.setString("GAME OVER");
}

void GameOverState::handleInput(const float& dt)
{
}

void GameOverState::drawToTexture(Renderer& renderer)
{
	renderer.rtx->clear(bgFill);
}
