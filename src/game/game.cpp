#include "game.h"
#include "../util/constants.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

Game::Game() : window(nullptr), renderer(nullptr), event(nullptr), quit(false), timer(nullptr), delta(0),
               player(nullptr), ball(nullptr), enemy(nullptr) {}

bool Game::init() {
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        SDL_Log("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    event = new SDL_Event();

    timer = new Timer();

    player = new Player({10, 10, BLOCK_WIDTH, BLOCK_HEIGHT});
    enemy = new Enemy({SCREEN_WIDTH - 10, 10, BLOCK_WIDTH, BLOCK_HEIGHT});
    ball = new Ball({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_WIDTH, BALL_HEIGHT}, -BALL_VELOCITY, -BALL_VELOCITY);

    return true;
}

bool Game::loadMedia() {
    return true;
}

void Game::update() {
    timer->start();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    player->render(renderer);
    enemy->render(renderer);
    ball->render(renderer);
    player->update(delta);
    enemy->update(delta, ball->getBody());
    ball->update(delta, player->getBody(), enemy->getBody());

    SDL_RenderPresent(renderer);

    if (ball->isOutOfScreen()) {
        ball->restart({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_WIDTH, BALL_HEIGHT}, -BALL_VELOCITY, -BALL_VELOCITY);
    }

    delta = timer->getTicks() * 0.001;
}

void Game::handleInput() {
    if (SDL_PollEvent(event) != 0) {
        if (event->type == SDL_QUIT) {
            quit = true;
        }
    }
    player->handleInput(event);
}

bool Game::isQuit() {
    return quit;
}

void Game::close() {
    delete ball;
    delete enemy;
    delete player;

    delete timer;

    delete event;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}