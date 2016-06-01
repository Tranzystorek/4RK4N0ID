/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ball.cpp
 * Author: marcin
 * 
 * Created on 27 kwietnia 2016, 23:54
 */

#include "Ball.h"

//#include <iostream>

Ball::Ball()
{
    color_ = Constants::BLACK;
    
    rectangle_.w = rectangle_.h = Constants::BALL_WIDTH;
    
    reset(Constants::SCREEN_WIDTH / 2 - Constants::BALL_WIDTH / 2);
}

void Ball::handle_events(SDL_Event& e)
{
    if(!launched_)
    {
        velocity_.setX(0);
        
        const Uint8* state = SDL_GetKeyboardState(NULL);
        
        if(state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT])
            velocity_.setX(-1);
    
        else if(state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_LEFT])
            velocity_.setX(1);
        
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
        {
            launched_ = true;
            
            velocity_.setY(-1);
            
            //if(!velocity_.getX())
            //    velocity_.setX(1);
        }
    }
}

void Ball::update(int delta)
{
    //window frame collisions
    //quicker code to reset position in conditional statements
    if(  (position_.getX() < 0 && position_.setX(0))
      || (position_.getX() + Constants::BALL_WIDTH > Constants::SCREEN_WIDTH
      &&  position_.setX(Constants::SCREEN_WIDTH - Constants::BALL_WIDTH)) )
    
        velocity_.setX( -(velocity_.getX()) );
    
    if(  (position_.getY() < 0 && position_.setY(0)) ) 
      //|| (position_.getY() + Constants::BALL_WIDTH > Constants::SCREEN_HEIGHT
      //&&  position_.setY(Constants::SCREEN_HEIGHT - Constants::BALL_WIDTH)) )
        
        velocity_.setY( -(velocity_.getY()) );
    
    //std::cout << velocity_.getX() << " " << velocity_.getY() << std::endl;
    
    if(!launched_)
        position_ += velocity_ * (Constants::PAD_SPEED * delta / 1000);
    
    else
        position_ += velocity_ * (Constants::BALL_SPEED * delta / 1000);
    
    rectangle_.x = position_.getX();
    rectangle_.y = position_.getY();
}

void Ball::on_collision(Constants::CollisionType ct)
{
    switch(ct)
    {
    case Constants::HOR:
        velocity_.setY(-velocity_.getY());
        break;
    
    case Constants::VERT:
        velocity_.setX(-velocity_.getX());
        break;
    }
}

void Ball::on_pad_collision(double dir)
{
    velocity_.setY(-(velocity_.getY()));
    
    double vx = velocity_.getX();
    
    if(dir > 0)
    {
        if(vx < 2)
            vx += 0.4;
    }
        
    else if(dir < 0)
    {
        if(vx > -2)
            vx -= 0.4;
    }
    
    velocity_.setX(vx);
}

void Ball::reset(int x)
{
    launched_ = false;
    
    position_ = Vector2D(x, Constants::SCREEN_HEIGHT * 5 / 6 - Constants::BALL_WIDTH);
    
    rectangle_.x = position_.getX();
    rectangle_.y = position_.getY();
    
    velocity_ = Vector2D();
}