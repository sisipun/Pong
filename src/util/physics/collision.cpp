#include "collision.h"

int checkLeftCollision(Body ball, Body block) {
    float leftBall;
    float rightBlock;
    float topBall, topBlock;
    float bottomBall, bottomBlock;
    float horizontalCenterBall, horizontalCenterBlock;

    leftBall = ball.x;
    topBall = ball.y;
    bottomBall = ball.y + ball.height;
    horizontalCenterBall = ball.y + ball.height / 2;

    rightBlock = block.x + block.width;
    topBlock = block.y;
    bottomBlock = block.y + block.height;
    horizontalCenterBlock = block.y + block.height / 2;

    if (rightBlock >= leftBall && bottomBlock >= topBall && topBlock <= bottomBall) {
        if (horizontalCenterBall > horizontalCenterBlock) {
            return 1;
        } else {
            return -1;
        }
    }

    return 0;
}

int checkRightCollision(Body ball, Body block) {
    float rightBall;
    float leftBlock;
    float topBall, topBlock;
    float bottomBall, bottomBlock;
    float horizontalCenterBall, horizontalCenterBlock;

    rightBall = ball.x + ball.width;
    topBall = ball.y;
    bottomBall = ball.y + ball.height;
    horizontalCenterBall = ball.y + ball.height / 2;

    leftBlock = block.x + block.width;
    topBlock = block.y;
    bottomBlock = block.y + block.height;
    horizontalCenterBlock = block.y + block.height / 2;

    if (leftBlock <= rightBall && bottomBlock >= topBall && topBlock <= bottomBall) {
        if (horizontalCenterBall > horizontalCenterBlock) {
            return 1;
        } else {
            return -1;
        }
    }

    return 0;
}