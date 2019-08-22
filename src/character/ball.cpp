#include "ball.h"
#include "../util/constants.h"
#include "../util/physics/collision.h"
#include <cmath>

Ball::Ball(Body body, float horizontalVelocity, float verticalVelocity) {
    this->body = body;
    this->verticalVelocity = verticalVelocity;
    this->horizontalVelocity = horizontalVelocity;
}

void Ball::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect rect = {
            static_cast<int>(body.x),
            static_cast<int>(body.y),
            static_cast<int>(body.width),
            static_cast<int>(body.height)
    };
    SDL_RenderFillRect(renderer, &rect);
}

void Ball::update(float delta, Body playerBody) {
    this->body.x += this->horizontalVelocity * delta;
    this->body.y += this->verticalVelocity * delta;

    if (this->body.y + this->body.height > SCREEN_HEIGHT || this->body.y < 0) {
        this->verticalVelocity = -this->verticalVelocity;
    }

    int collisionResult = checkLeftCollision(this->body, playerBody);
    SDL_Log("Coll %d", collisionResult);

    if (collisionResult != 0) {
        this->verticalVelocity = collisionResult * fabsf(this->verticalVelocity);
        this->horizontalVelocity = -this->horizontalVelocity;
    }
}

void Ball::restart(Body body, float horizontalVelocity, float verticalVelocity) {
    this->body = body;
    this->horizontalVelocity = horizontalVelocity;
    this->verticalVelocity = verticalVelocity;
}

bool Ball::isOutOfScreen() {
    return this->body.x < 0 || this->body.x + this->body.width > SCREEN_WIDTH;
}