#include "world.h"

World::World(Vector2u size){
    blockSize = 16;

    screenSize = size;
    respawnApple();
    appleShape.setFillColor(Color::Red);
    appleShape.setRadius(blockSize / 2);

    for(int i = 0; i < 4; i++){
        bounds[i].setFillColor(Color(150, 0, 0));
        float bw = i % 2 == 0 ? screenSize.x : blockSize;
        float bh = i % 2 == 0 ? blockSize : screenSize.y;
        bounds[i].setSize(Vector2f(bw, bh));

        if(i < 2){
            bounds[i].setPosition(0, 0);
        } else {
            bounds[i].setOrigin(bounds[i].getSize());
            bounds[i].setPosition(Vector2f(screenSize));
        }
    }
};

World::~World(){

}

int World::getBlockSize(){
    return blockSize;
}

void World::respawnApple(){
    int maxX = screenSize.x/blockSize - 2;
    int maxY = screenSize.y/blockSize - 2;
    item = Vector2i(rand() % maxX + 1, rand() % maxY + 1);
    appleShape.setPosition(item.x * blockSize, item.y * blockSize);
}

void World::update(Snake& snake){
    Vector2i snakePosition = snake.getPosition();
    int gridX = screenSize.x / blockSize;
    int gridY = screenSize.y / blockSize;

    if(snakePosition == item){
        snake.extend();
        snake.increaseScore();
        respawnApple();
    }

    if(snakePosition.x <= 0 || snakePosition.y <= 0) snake.lose();
    if(snakePosition.x >= gridX - 1 || snakePosition.y >= gridY - 1) snake.lose();
}

void World::render(Screen& screen){
    for(int i = 0; i < 4; i++) screen.draw(bounds[i]);
    screen.draw(appleShape);
}