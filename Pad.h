/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pad.h
 * Author: marcin
 *
 * Created on 27 kwietnia 2016, 12:43
 */

#include "Object.h"

#ifndef PAD_H
#define PAD_H

class Pad : public Object
{
public:
    Pad();
    
    void handle_events(SDL_Event& e);
    void update(int delta);
    
    void on_collision();
    
    Vector2D get_velocity() const {return velocity_;}

private:
    
    Vector2D velocity_;
    
    bool movable_;
};

#endif /* PAD_H */

