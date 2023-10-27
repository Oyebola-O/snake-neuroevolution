#pragma once
#include "headers.h"
#include "screen.h"
#include "inputManager.h"

class Button {
	RectangleShape shape;
	Text text;

public:
	Button(const string&, Vector2f, Vector2f);
	bool isHovered(InputManager&);
	bool isClicked(InputManager&);

	void render(Screen&);
	void update(InputManager&);
};