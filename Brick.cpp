/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Brick.cpp
 * Author: marcin
 * 
 * Created on 31 maja 2016, 22:01
 */

#include "Brick.h"

Brick::Brick(int x, int y, SDL_Color clr)
{
    position_ = Vector2D(x, y);
    
    rectangle_.x = position_.getX();
    rectangle_.y = position_.getY();
    
    rectangle_.w = Constants::BRICK_WIDTH;
    rectangle_.h = Constants::BRICK_HEIGHT;
    
    color_ = clr;
}

