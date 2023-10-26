#pragma once
#include "headers.h"
#include "screen.h"
#include "nn.h"

struct SnakeBlock {
    Vector2i position;
    SnakeBlock(int x, int y) : position(x, y){}
};

enum class Direction {
    None, Up, Down, Left, Right
};

class Snake {
    int blockSize;
    int speed;
    int lives;
    int score;
    bool lost;

    Direction currDirection;
    RectangleShape bodyRect;
    vector<SnakeBlock> snakeBody;
    NeuralNetwork brain;
    
    void checkCollision();

    public:
        Snake(int);
        Snake(Snake, Snake);
        ~Snake();

        int getSpeed();
        int getLives();
        int getScore();
        bool hasLost();

        Vector2i getPosition();
        Direction getDirection();

        void move();
        void tick();
        void lose();
        void reset(); // Reset to starting position
        void extend();
        void toggleLost();
        void increaseScore();
        void render(Screen&);
        void setDirection(Direction);
};