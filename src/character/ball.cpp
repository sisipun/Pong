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

void Ball::update(float delta, Body playerBody, Body enemyBody) {
    this->body.x += this->horizontalVelocity * delta;
    this->body.y += this->verticalVelocity * delta;

    if (this->body.y + this->body.height > SCREEN_HEIGHT || this->body.y < 0) {
        this->verticalVelocity = -this->verticalVelocity;
    }

    int playerCollisionResult = checkLeftCollision(this->body, playerBody);
    if (playerCollisionResult != 0) {
        this->verticalVelocity = playerCollisionResult * fabsf(this->verticalVelocity);
        this->horizontalVelocity = -this->horizontalVelocity;
    }

    int enemyCollisionResult = checkRightCollision(this->body, enemyBody);
    if (enemyCollisionResult != 0) {
        this->verticalVelocity = enemyCollisionResult * fabsf(this->verticalVelocity);
        this->horizontalVelocity = -this->horizontalVelocity;
    }
}

void Ball::restart(Body body, float horizontalVelocity, float verticalVelocity) {
    this->body = body;
    this->horizontalVelocity = horizontalVelocity;
    this->verticalVelocity = verticalVelocity;
}

Body Ball::getBody() {
    return this->body;
}