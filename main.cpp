#include "headers.h"
#include "game.h"
#include "nn.h"


int main(int argc, char* argv[]){
    srand(time(nullptr));
    Game game;

    while(game.isOpen()){
        game.handleInput();
        game.update();
        game.render();
        game.restartClock();
    }
}