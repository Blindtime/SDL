#include "Game.hpp"

int main(int argc, char* args[]){

    Game game;

    game.init();

    while(game.running()){
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}