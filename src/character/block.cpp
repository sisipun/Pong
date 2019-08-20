#include "block.h"

Block::Block(SDL_Rect body) {
    this->body = body;
}

void Block::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &body);
}