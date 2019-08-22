#ifndef PLAYER_H
#define PLAYER_H

#include "block.h"

class Player {
public:
    explicit Player(Body body);

    ~Player();

    void render(SDL_Renderer *renderer);

    void update(float delta);

    void handleInput(SDL_Event *event);

    Body getBody();

private:
    Block *block;
};


#endif