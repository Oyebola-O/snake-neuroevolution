#pragma once
#include "headers.h"

class InputManager {
	unordered_map<Keyboard::Key, bool> keyStates;
	unordered_map<Mouse::Button, bool> buttonStates;
	Vector2i mousePosition;

public:
	bool isKeyPressed(Keyboard::Key);
	bool isButtonPressed(Mouse::Button);
	Vector2i getMousePosition();

	void update(Event&);
};