#ifndef ENEMY_H
#define ENEMY_H

#include "SDL2/SDL.h"
#include "block.h"
#include "../util/physics/body.h"

class Enemy {
public:
    explicit Enemy(Body body);

    ~Enemy();

    void render(SDL_Renderer *renderer);

    void update(float delta, Body ballBody);

    Body getBody();

private:
    Block *block;
};

#endif