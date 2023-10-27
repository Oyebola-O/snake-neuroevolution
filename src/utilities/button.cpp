#include "button.h"

Button::Button(const string& title, Vector2f position, Vector2f size){
	shape.setSize(size);
	shape.setOrigin(shape.getGlobalBounds().left + size.x / 2, shape.getGlobalBounds().top + size.y / 2);
	shape.setPosition(position);
	shape.setFillColor(Color::Magenta);

	
	text.setFont(font);
	text.setString(title);
	text.setCharacterSize(20);
	text.setStyle(Text::Bold);
	text.setOrigin(text.getGlobalBounds().left + text.getGlobalBounds().width / 2, text.getGlobalBounds().top + text.getGlobalBounds().height / 2);
	text.setPosition(position);
	text.setFillColor(Color::White);
}

bool Button::isHovered(InputManager& inputManager){
	return shape.getGlobalBounds().contains(Vector2f(inputManager.getMousePosition()));
}

bool Button::isClicked(InputManager& inputManager){
	return isHovered(inputManager) && inputManager.isButtonPressed(Mouse::Left);
}

void Button::render(Screen& screen) {
	screen.draw(shape);
	screen.draw(text);
}

void Button::update(InputManager& inputManager){
	if(isHovered(inputManager)){
		shape.setFillColor(Color::Yellow);
	} else {
		shape.setFillColor(Color::Magenta);
	}
}
