
#pragma once
#include "headers.h"
#include "screen.h"
#include "button.h"

class GameState {
public:
	virtual ~GameState(){}
	virtual void update(float, InputManager &) = 0;
	virtual void render(Screen &) = 0;
	virtual void handleInput(Screen &, InputManager &) = 0;
};

class MainMenu : public GameState {
	Button play;
	Button simulate;
	Button exit;
public:
	MainMenu();
	void update(float, InputManager &);
	void render(Screen &);
	void handleInput(Screen &, InputManager &);
};

class GamePlay : public GameState {
public:
	void update(float, InputManager &);
	void render(Screen &);
	void handleInput(Screen &, InputManager &);
};

class Simulation : public GameState {
public:
	void update(float, InputManager &);
	void render(Screen &);
	void handleInput(Screen &, InputManager &);
};