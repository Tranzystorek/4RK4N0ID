/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BrickGenerator.cpp
 * Author: marcin
 * 
 * Created on 31 maja 2016, 22:12
 */

#include "BrickGenerator.h"

BrickGenerator::BrickGenerator()
{
    row_ = column_ = 0;
    
    done_ = false;
}

Brick* BrickGenerator::generate_brick()
{
    if(done_)
        return NULL;
    
    Brick* br = new Brick(Constants::MATRIX_X + column_ * (Constants::BRICK_WIDTH + Constants::GAP_SIZE),
                          Constants::MATRIX_Y + row_ * (Constants::BRICK_HEIGHT + Constants::GAP_SIZE),
                          Constants::RED);
    
    row_ = (column_ < Constants::N_COLUMNS - 1) ? row_ : row_ + 1;
    column_ = (column_ < Constants::N_COLUMNS -1) ? column_ + 1 : 0;
    
    if(row_ == Constants::N_ROWS)
        done_ = true;
    
    return br;
}