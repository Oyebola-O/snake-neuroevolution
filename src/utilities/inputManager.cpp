#include "inputManager.h"

bool InputManager::isKeyPressed(Keyboard::Key keyPressed) {
	return keyStates[keyPressed];
}

bool InputManager::isButtonPressed(Mouse::Button buttonPressed) {
	return buttonStates[buttonPressed];
}

Vector2i InputManager::getMousePosition() { return mousePosition; }

void InputManager::update(Event &event) {
	switch (event.type) {
		case Event::KeyPressed:
			keyStates[event.key.code] = true; break;

		case Event::KeyReleased:
			keyStates[event.key.code] = false; break;

		case Event::MouseButtonPressed:
			buttonStates[event.mouseButton.button] = true; break;

		case Event::MouseButtonReleased:
			buttonStates[event.mouseButton.button] = false; break;

		case Event::MouseMoved:
			mousePosition = {event.mouseMove.x, event.mouseMove.y}; break;
		default: break;
	}
}