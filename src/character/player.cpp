#include "player.h"
#include "../util/constants.h"

Player::Player(Body body) {
    this->block = new Block(body, BLOCK_VELOCITY);
}

Player::~Player() {
    delete this->block;
}

void Player::render(SDL_Renderer *renderer) {
    this->block->render(renderer);
}

void Player::update(float delta) {
    this->block->update(delta);
}

void Player::handleInput(SDL_Event *event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_UP:
                block->moveUp();
                break;
            case SDLK_DOWN:
                block->moveDown();
                break;
        }
    }
    if (event->type == SDL_KEYUP) {
        switch (event->key.keysym.sym) {
            case SDLK_UP:
                block->stopUp();
                break;
            case SDLK_DOWN:
                block->stopDown();
                break;
        }
    }
}