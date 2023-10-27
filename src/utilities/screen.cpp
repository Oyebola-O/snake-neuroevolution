#include "screen.h"

void Screen::setup(const string &setTitle, const Vector2u &setSize) {
	title = setTitle;
	size = setSize;
	create();
}

void Screen::create() {
	screen.create({size.x, size.y, 32}, title, Style::Default);
}

// Public
Screen::Screen() { setup("Game Window", Vector2u(640, 480)); }

Screen::Screen(const string &setTitle, const Vector2u &setSize) {
	setup(setTitle, setSize);
}

Screen::~Screen() { close(); }

bool Screen::isOpen() { return screen.isOpen(); }

bool Screen::pollEvent(Event &event) { return screen.pollEvent(event); }

Vector2u Screen::getScreenSize() { return size; }

void Screen::beginDraw() { screen.clear(Color::Black); }

void Screen::endDraw() { screen.display(); }

void Screen::close() { screen.close(); }

void Screen::draw(Drawable &object) { screen.draw(object); }
