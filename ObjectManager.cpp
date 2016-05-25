/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ObjectManager.cpp
 * Author: marcin
 * 
 * Created on 27 kwietnia 2016, 12:22
 */

#include "ObjectManager.h"
#include <cstddef> //for NULL

ObjectManager* ObjectManager::p_instance_ = NULL;

ObjectManager* ObjectManager::Instance()
{
    if (!p_instance_)
        p_instance_ = new ObjectManager();

    return p_instance_;
}

void ObjectManager::add(Object* obj)
{
    objects_.push_back(obj);
}

ObjectManager::ObjectManager()
{
    pad_ = new Pad;
    ball_ = new Ball;
}

void ObjectManager::handle_events(SDL_Event& e)
{
    pad_->handle_events(e);
    ball_->handle_events(e);
    
    for(std::vector<Object*>::iterator it = objects_.begin(); it != objects_.end(); it++)
        (*it)->handle_events(e);
}

void ObjectManager::update(int delta)
{
    check_collisions();
    
    pad_->update(delta);
    ball_->update(delta);
    
    for(std::vector<Object*>::iterator it = objects_.begin(); it != objects_.end(); it++)
        (*it)->update(delta);
}

void ObjectManager::render(SDL_Renderer* renderer)
{
    pad_->render(renderer);
    ball_->render(renderer);
    
    for(std::vector<Object*>::iterator it = objects_.begin(); it != objects_.end(); it++)
        (*it)->render(renderer);
}

bool ObjectManager::rect_collision(SDL_Rect a, SDL_Rect b)
{
    if(a.x > b.x + b.w || b.x > a.x + a.w)
        return false;
    
    if(a.y > b.y + b.h || b.y > a.y + a.h)
        return false;
    
    return true;
}

void ObjectManager::check_collisions()
{
    //Constants::CollisionType ct;
    
    if(rect_collision(ball_->rectangle_, pad_->rectangle_))
        ball_->on_collision();
}