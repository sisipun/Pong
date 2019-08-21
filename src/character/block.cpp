#include "block.h"

Block::Block(Body body, float velocity) {
    this->body = body;
    this->velocity = velocity;
    this->isMoveUp = false;
    this->isMoveDown = false;
}

void Block::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_Rect rect = {
            static_cast<int>(body.x),
            static_cast<int>(body.y),
            static_cast<int>(body.width),
            static_cast<int>(body.height)
    };
    SDL_RenderFillRect(renderer, &rect);
}

void Block::update(float delta) {
    if (this->isMoveUp) {
        this->body.y -= velocity * delta;
    } else if (this->isMoveDown) {
        this->body.y += velocity * delta;
    }
}

void Block::moveUp() {
    this->isMoveDown = false;
    this->isMoveUp = true;
}

void Block::moveDown() {
    this->isMoveUp = false;
    this->isMoveDown = true;
}

void Block::stopUp() {
    this->isMoveUp = false;
}

void Block::stopDown() {
    this->isMoveDown = false;
}