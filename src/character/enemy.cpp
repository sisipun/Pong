#include "enemy.h"

#include "../util/constants.h"

Enemy::Enemy(Body body) {
    this->block = new Block(body, ENEMY_BLOCK_VELOCITY);
}

Enemy::~Enemy() {
    delete this->block;
}

void Enemy::render(SDL_Renderer *renderer) {
    this->block->render(renderer);
}

void Enemy::update(float delta, Body ballBody) {
    this->block->update(delta);

    float ballHorizontalCenter = ballBody.y + ballBody.height / 2;
    float blockHorizontalCenter = block->getBody().y + block->getBody().height / 2;
    if (ballHorizontalCenter > blockHorizontalCenter) {
        block->moveDown();
    } else if (ballHorizontalCenter < blockHorizontalCenter) {
        block->moveUp();
    }
}

Body Enemy::getBody() {
    return this->block->getBody();
}