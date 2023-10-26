#pragma once
#include "headers.h"
#include "screen.h"
#include "snake.h"

class World {
    int blockSize;
    Vector2i item;
    Vector2u screenSize;
    CircleShape appleShape;
    RectangleShape bounds[4];

    public:
        World(Vector2u);
        ~World();

        int getBlockSize();
        
        void respawnApple();
        void update(Snake&);
        void render(Screen&);
};