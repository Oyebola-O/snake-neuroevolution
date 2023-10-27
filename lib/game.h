#pragma once
#include "headers.h"
#include "screen.h"
#include "gamestate.h"
#include "inputManager.h"

class Game {
	float frameRate = 60; //Hz
	Time dt;
	Clock clock;
	Screen screen;
	GameState* currState;
	InputManager intputManager;

public:
	Game();

	bool screenOpen();

	void ddt();
	void update();
	void render();
	void handleInput();
	void setState(GameState*);
};