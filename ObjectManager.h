/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ObjectManager.h
 * Author: marcin
 *
 * Created on 27 kwietnia 2016, 12:22
 */

#include <SDL2/SDL.h>
#include "Ball.h"
#include "Pad.h"
#include <vector>

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class ObjectManager
{
public:
    static ObjectManager* Instance();
    
    void handle_events(SDL_Event& e);
    void update(int delta);
    void render(SDL_Renderer* renderer);

    void add(Object* obj);

private:
    ObjectManager();
    
    void check_collisions();
    
    bool rect_collision(SDL_Rect a, SDL_Rect b);

    static ObjectManager* p_instance_;

    std::vector<Object*> objects_;
    
    Ball* ball_;
    
    Pad* pad_;
};

#endif /* OBJECTMANAGER_H */

