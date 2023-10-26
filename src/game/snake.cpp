#include "snake.h"

Snake::Snake(int size): brain(vector<int>{4,4,4,4}){
    blockSize = size;
    bodyRect.setSize(Vector2f(blockSize - 1, blockSize - 1));
    reset();
}

Snake::~Snake(){
    
}

int Snake::getSpeed(){
    return speed;
}

int Snake::getLives(){
    return lives;
}

int Snake::getScore(){
    return score;
}

bool Snake::hasLost(){
    return lost;
}

Vector2i Snake::getPosition(){
    return snakeBody.empty() ? Vector2i(1, 1) : snakeBody.front().position;
}

Direction Snake::getDirection(){
    return currDirection;
}

void Snake::move(){
    // TODO: Fix this function later
    Vector2i next = snakeBody.front().position;

    if(currDirection == Direction::Left) --next.x;
    if(currDirection == Direction::Right) ++next.x;
    if(currDirection == Direction::Up) --next.y;
    if(currDirection == Direction::Down) ++next.y;
    // For each block in snakeBody, update [i + 1] to [i]

    for(int i = 0; i < snakeBody.size(); i++){
        Vector2i temp = snakeBody[i].position;
        snakeBody[i].position = next;
        next = temp;
    }
}

void Snake::tick(){
    if(snakeBody.empty() || currDirection == Direction::None) return;
    move();
}

void Snake::lose(){
    lost = true;
}

void Snake::reset(){
    snakeBody.clear();

    snakeBody.push_back(SnakeBlock(5, 7));
    snakeBody.push_back(SnakeBlock(5, 6));
    snakeBody.push_back(SnakeBlock(5, 5));

    setDirection(Direction::None);
    speed = 15;
    lives = 3;
    score = 0;
    lost = false;
}

void Snake::extend(){
    Vector2i lastPos = snakeBody.back().position;
    snakeBody.push_back(SnakeBlock(lastPos.x, lastPos.y));
}

void Snake::render(Screen& screen){
    if(snakeBody.empty()) return;

    bodyRect.setFillColor(Color::Yellow);
    for(int i = 0; i < snakeBody.size(); i++){
        auto curr = snakeBody[i];
        if(i == 1) bodyRect.setFillColor(Color::Green);
        bodyRect.setPosition(curr.position.x * blockSize, curr.position.y * blockSize);
        screen.draw(bodyRect);
    }
}

void Snake::toggleLost(){
    lost = !lost;
}

void Snake::increaseScore(){
    score += 10;
}

void Snake::setDirection(Direction direction){
    currDirection = direction;
}