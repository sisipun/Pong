#ifndef BLOCK_H
#define BLOCK_H

#include <SDL2/SDL.h>

class Block {
public:
    Block(SDL_Rect body);

    void render(SDL_Renderer *renderer);

private:
    SDL_Rect body;
};

#endif