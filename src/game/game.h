#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "../character/block.h"

class Game {
public:
    Game();

    bool init();

    bool loadMedia();

    void update();

    void handleInput();

    bool isQuit();

    void close();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;
    Block* block;
    bool quit;
};

#endif