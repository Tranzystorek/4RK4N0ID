/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constants.h
 * Author: marcin
 *
 * Created on 10 maja 2016, 11:42
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
    enum CollisionType {NONE, VERT, HOR};

    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;
    
    const int BALL_WIDTH = 20;
    const double BALL_SPEED = 300;
    
    const int PAD_WIDTH = 100;
    const int PAD_HEIGHT = 30;
    const double PAD_SPEED = 700;
    
    const SDL_Color BLACK = {0, 0, 0, 255};
    const SDL_Color RED = {255, 0, 0, 255};
    const SDL_Color BLUE = {0, 0, 255, 255};
}

#endif /* CONSTANTS_H */

