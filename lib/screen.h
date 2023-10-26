#pragma once
#include "headers.h"

class Screen {
    bool fullScreen;
    string title;
    Vector2u size;
    RenderWindow screen;

    void setup(const string&, const Vector2u&);
    void create();
    void destroy();

    public:
        Screen();
        Screen(const string&, const Vector2u&);
        ~Screen();

        bool isOpen();
        bool isFullScreen();
        Vector2u getScreenSize();

        void beginDraw();
        void endDraw();
        void update();
        void draw(Drawable& object);
        void toggleFullScreen();
};