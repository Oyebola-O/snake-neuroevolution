#include "headers.h"
#include "game.h"

Font font;

int main(int argc, char *argv[]) {
	if(!font.loadFromFile("font.ttf")) { cerr << "Couldn't load font" << endl; }
	
	Game game;

	while (game.screenOpen()) {
		game.handleInput();
		game.update();
		game.render();
		game.ddt();
	}
}