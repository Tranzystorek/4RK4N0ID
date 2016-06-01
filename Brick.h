/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Brick.h
 * Author: marcin
 *
 * Created on 31 maja 2016, 22:01
 */

#include "Object.h"

#ifndef BRICK_H
#define BRICK_H

class Brick : public Object
{
public:
    Brick(int x, int y, SDL_Color clr);
    
private:
    
};

#endif /* BRICK_H */

