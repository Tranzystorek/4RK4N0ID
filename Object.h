/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.h
 * Author: marcin
 *
 * Created on 27 kwietnia 2016, 12:23
 */

#include <SDL2/SDL.h>
#include "Vector2D.h"
#include "Constants.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    
    virtual void handle_events(SDL_Event& e) {};
    virtual void update(int delta) {};
    virtual void render(SDL_Renderer* renderer);
    
protected:

    Vector2D position_;
    
    SDL_Rect rectangle_;
    SDL_Color color_;
    
    friend class ObjectManager;
};

#endif /* OBJECT_H */

