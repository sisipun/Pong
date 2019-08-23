#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "../character/block.h"
#include "../util/time/timer.h"
#include "../character/player.h"
#include "../character/enemy.h"
#include "../character/ball.h"

class Game {
public:
    Game();

    bool init();

    bool loadMedia();

    void update();

    void handleInput();

    bool isQuit();

    void close();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;
    bool quit;

    Timer *timer;
    float delta;

    Player *player;
    Ball *ball;
    Enemy *enemy;
};

#endif