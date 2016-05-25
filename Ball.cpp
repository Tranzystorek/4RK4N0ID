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

Ball::Ball()
{
    color_ = Constants::BLACK;
    
    position_ = Vector2D(Constants::SCREEN_WIDTH / 2 - Constants::BALL_WIDTH / 2,
                         Constants::SCREEN_HEIGHT / 2 - Constants::BALL_WIDTH / 2);
    
    rectangle_.x = position_.getX();
    rectangle_.y = position_.getY();
    
    rectangle_.w = rectangle_.h = Constants::BALL_WIDTH;
    
    velocity_ = Vector2D(1, 1);
}

void Ball::update(int delta)
{
    position_ += velocity_ * (Constants::BALL_SPEED * delta / 1000);
    
    if(  (position_.getX() < 0 && position_.setX(0))
      || (position_.getX() + Constants::BALL_WIDTH > Constants::SCREEN_WIDTH
      &&  position_.setX(Constants::SCREEN_WIDTH - Constants::BALL_WIDTH)) )
    
        velocity_.setX( -(velocity_.getX()) );
    
    if(  (position_.getY() < 0 && position_.setY(0))
      || (position_.getY() + Constants::BALL_WIDTH > Constants::SCREEN_HEIGHT
      &&  position_.setY(Constants::SCREEN_HEIGHT - Constants::BALL_WIDTH)) )
        
        velocity_.setY( -(velocity_.getY()) );
    
    rectangle_.x = position_.getX();
    rectangle_.y = position_.getY();
}

void Ball::on_collision()
{
    velocity_.setY(-velocity_.getY());
}