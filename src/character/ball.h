#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "../util/physics/body.h"

class Ball {
public:
    Ball(Body body, float horizontalVelocity, float verticalVelocity);

    void render(SDL_Renderer *renderer);

    void update(float delta, Body playerBody, Body enemyBody);

    void restart(Body body, float horizontalVelocity, float verticalVelocity);

    bool isOutOfScreen();

    Body getBody();

private:
    Body body;
    float horizontalVelocity;
    float verticalVelocity;
};

#endif