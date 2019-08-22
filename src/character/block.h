#ifndef BLOCK_H
#define BLOCK_H

#include <SDL2/SDL.h>
#include "../util/physics/body.h"

class Block {
public:
    Block(Body body, float velocity);

    void render(SDL_Renderer *renderer);

    void update(float delta);

    void moveUp();

    void moveDown();

    void stopUp();

    void stopDown();

    Body getBody();

private:
    Body body;
    float velocity;
    bool isMoveUp;
    bool isMoveDown;
};

#endif