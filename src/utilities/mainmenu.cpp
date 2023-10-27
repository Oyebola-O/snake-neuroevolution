#include "gamestate.h"

MainMenu::MainMenu()
		: play("Play Game", Vector2f(400, 200), Vector2f(120, 50)),
			simulate("Simulate", Vector2f(400, 300), Vector2f(120, 50)),
			exit("Exit", Vector2f(400, 400), Vector2f(120, 50)) {}

void MainMenu::update(float dt, InputManager& inputManager) {
	play.update(inputManager);
	simulate.update(inputManager);
	exit.update(inputManager);
}

void MainMenu::render(Screen &screen) {
	play.render(screen);
	simulate.render(screen);
	exit.render(screen);
}

void MainMenu::handleInput(Screen &screen, InputManager & inputManager) {
	if(play.isClicked(inputManager)) cout << "Lets play" << endl;
	if(simulate.isClicked(inputManager)) cout << "Lets simulate" << endl;
	if(exit.isClicked(inputManager)) cout << "Lets Exit" << endl;
}