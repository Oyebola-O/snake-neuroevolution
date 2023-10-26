#include "game.h"

Game::Game():	
	screen("Snake", Vector2u(800, 640)),
	world(Vector2u(800, 640)),
	snake(16){
}


Game::~Game(){

}


bool Game::isOpen(){
  return screen.isOpen();
}


Time Game::getElaspedTime(){
    return timeElapsed;
}


void Game::handleInput(){
	if(Keyboard::isKeyPressed(Keyboard::Up)){
			if(snake.getDirection() == Direction::Down) return;
			snake.setDirection(Direction::Up);
	}

	if(Keyboard::isKeyPressed(Keyboard::Down)){
			if(snake.getDirection() == Direction::Up) return;
			snake.setDirection(Direction::Down);
	}

	if(Keyboard::isKeyPressed(Keyboard::Left)){
			if(snake.getDirection() == Direction::Right) return;
			snake.setDirection(Direction::Left);
	}

	if(Keyboard::isKeyPressed(Keyboard::Right)){
			if(snake.getDirection() == Direction::Left) return;
			snake.setDirection(Direction::Right);
	}
}


void Game::update(){
	screen.update();
	float timeStep = 1.0f / snake.getSpeed();

	if(timeElapsed.asSeconds() >= timeStep){
			snake.tick();
			world.update(snake);
			timeElapsed -= seconds(timeStep);
			if(snake.hasLost()) snake.reset();
	}
}


void Game::render(){
    screen.beginDraw();

    world.render(screen);
    snake.render(screen);

    screen.endDraw();
}


void Game::restartClock(){
    timeElapsed += gameClock.restart();
}