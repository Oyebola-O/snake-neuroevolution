#pragma once
#include "headers.h"

class Screen {
	string title;
	Vector2u size;
	RenderWindow screen;

	void setup(const string &, const Vector2u &);
	void create();

public:
	Screen();
	Screen(const string &, const Vector2u &);
	~Screen();

	bool isOpen();
	bool pollEvent(Event &);
	Vector2u getScreenSize();

	void beginDraw();
	void endDraw();
	void close();
	void draw(Drawable &object);
};