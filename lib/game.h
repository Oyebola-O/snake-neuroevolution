#pragma once
#include "headers.h"
#include "screen.h"
#include "world.h"
#include "snake.h"

class Game {
    Clock gameClock;
    Time timeElapsed;

    Snake snake;
    World world;
    Screen screen;
    
    public:
        Game();
        ~Game();

        bool isOpen();
        Time getElaspedTime();

        void handleInput();
        void update();
        void render();
        void restartClock();
};