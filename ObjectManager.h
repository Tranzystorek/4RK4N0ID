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
#include "Text.h"
#include "BrickGenerator.h"

#include <list>

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class ObjectManager
{
public:
    static ObjectManager* Instance();
    
    void handle_events(SDL_Event& e);
    void update(int delta);
    void render(SDL_Renderer* renderer);

private:
    ObjectManager();
    
    void check_ball_brick_collision();
    
    Constants::CollisionType rect_collision(SDL_Rect a, SDL_Rect b);
    
    void check_ball_pad_collision();

    static ObjectManager* p_instance_;
    
    BrickGenerator brick_gen_;

    std::list<Brick*> bricks_;
    
    Ball* ball_;
    
    Pad* pad_;
    
    Text* points_text_;
    Text* lives_text_;
    Text* win_text_;
    Text* lose_text_;
    
    int lives_;
    int points_;
    
    bool defeat_;
    bool victory_;
};

#endif /* OBJECTMANAGER_H */

