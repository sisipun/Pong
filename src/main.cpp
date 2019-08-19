#include <iostream>

#include "game/game.h"

int main(int argc, char *argv[]) {
    Game game;
    if (!game.init()) {
        printf("Failed to initialize!\n");
        return -1;
    }
    if (!game.loadMedia()) {
        printf("Failed to load media!\n");
        return -1;
    }
    while (!game.isQuit()) {
        game.update();
        game.handleInput();
    }
    game.close();
    return 0;
}