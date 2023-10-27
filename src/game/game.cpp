#include "game.h"

Game::Game() : screen("Snake", Vector2u(800, 640)), intputManager() {
	currState = new MainMenu();
}

bool Game::screenOpen() { return screen.isOpen(); }

void Game::update() {
	Event event;
	while (screen.pollEvent(event)) {
		if (event.type == Event::Closed)
			screen.close();
		intputManager.update(event);
	}
	currState->update(dt.asSeconds(), intputManager);
	//TODO: Don't forget to subtract from dt
}

void Game::render() {
	screen.beginDraw();
	currState->render(screen);
	screen.endDraw();
}

void Game::setState(GameState *gameState) {
	if (currState)
		delete currState;
	currState = gameState;
}

void Game::ddt(){
	dt += clock.restart();
}

void Game::handleInput() { currState->handleInput(screen, intputManager); }