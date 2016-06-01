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
    
    const int N_LIVES = 3;

    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;
    
    const int BALL_WIDTH = 15;
    const double BALL_SPEED = 400;
    
    const int PAD_WIDTH = 120;
    const int PAD_HEIGHT = 30;
    const double PAD_SPEED = 700;
    
    const int BRICK_WIDTH = 70;
    const int BRICK_HEIGHT = 22;
    
    const int N_ROWS = 5;
    const int N_COLUMNS = 12;
    
    const int GAP_SIZE = 4;
    
    const int MATRIX_X = 70;
    const int MATRIX_Y = 40;
    
    const int POINTS_PER_BRICK = 100;
    
    const int FONT_SIZE = 24;
    
    const SDL_Color TRANSPARENT = {255, 255, 255, 0};
    const SDL_Color BLACK = {0, 0, 0, 255};
    const SDL_Color WHITE = {255, 255, 255, 255};
    const SDL_Color RED =   {255, 0, 0, 255};
    const SDL_Color BLUE =  {0, 0, 255, 255};
    const SDL_Color GREEN = {0, 255, 0, 255};
    const SDL_Color MELLOW = {0, 255, 255, 127};
}

#endif /* CONSTANTS_H */

