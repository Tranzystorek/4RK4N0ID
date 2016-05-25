/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.h
 * Author: marcin
 *
 * Created on 27 kwietnia 2016, 23:54
 */

#include "Object.h"

#ifndef BALL_H
#define BALL_H

class Ball : public Object
{
public:
    Ball();
    
    void handle_events(SDL_Event &e) {}
    void update(int delta);
    
    void on_collision();

private:
    
    Vector2D velocity_;
};

#endif /* BALL_H */

