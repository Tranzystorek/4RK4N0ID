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

ObjectManager* ObjectManager::p_instance_ = nullptr;

ObjectManager* ObjectManager::Instance()
{
    if (!p_instance_)
        p_instance_ = new ObjectManager();

    return p_instance_;
}

ObjectManager::ObjectManager()
{
    lives_ = Constants::N_LIVES;
    points_ = 0;
    
    victory_ = defeat_ = false;
    
    pad_ = new Pad;
    ball_ = new Ball;
    
    points_text_ = new Text(0, 0, "Score: " + std::to_string(points_));
    lives_text_ = new Text(900, 0, "Lives: " + std::to_string(lives_));
    
    win_text_ = new Text(0, Constants::SCREEN_HEIGHT / 2 - Constants::FONT_SIZE / 2,
                         "YOU WIN!");
    lose_text_ = new Text(0, Constants::SCREEN_HEIGHT / 2 - Constants::FONT_SIZE / 2,
                          "YOU LOSE!");
    
    Brick* br;
    
    while(br = brick_gen_.generate_brick())
        bricks_.push_back(br);
}

void ObjectManager::handle_events(SDL_Event& e)
{
    pad_->handle_events(e);
    ball_->handle_events(e);
    
    for(std::list<Brick*>::iterator it = bricks_.begin(); it != bricks_.end(); it++)
        (*it)->handle_events(e);
}

void ObjectManager::update(int delta)
{
    if(!victory_ && !defeat_) {
    
    check_ball_pad_collision();
    check_ball_brick_collision();
    
    Vector2D pos = ball_->position_;
    
    if(pos.getY() > Constants::SCREEN_HEIGHT)
    {
        ball_->reset(pad_->position_.getX() + Constants::PAD_WIDTH / 2 - Constants::BALL_WIDTH / 2);
        
        lives_--;
    }
    
    pad_->update(delta);
    ball_->update(delta);
    
    points_text_->set_text("Score: " + std::to_string(points_));
    lives_text_->set_text("Lives: " + std::to_string(lives_));
    
    lives_text_->set_x(Constants::SCREEN_WIDTH - lives_text_->get_width());
    
    win_text_->set_x(Constants::SCREEN_WIDTH / 2 - win_text_->get_width() / 2);
    lose_text_->set_x(Constants::SCREEN_WIDTH / 2 - lose_text_->get_width() / 2);
    
    for(std::list<Brick*>::iterator it = bricks_.begin(); it != bricks_.end(); it++)
        (*it)->update(delta);
    
    if(!lives_)
        defeat_ = true;
    
    else if(bricks_.empty())
        victory_ = true;
    
    }
}

void ObjectManager::render(SDL_Renderer* renderer)
{
    pad_->render(renderer);
    ball_->render(renderer);
    
    for(std::list<Brick*>::iterator it = bricks_.begin(); it != bricks_.end(); it++)
        (*it)->render(renderer);
    
    points_text_->render(renderer);
    lives_text_->render(renderer);
    
    if(victory_)
        win_text_->render(renderer);
    
    else if(defeat_)
        lose_text_->render(renderer);
}

Constants::CollisionType ObjectManager::rect_collision(SDL_Rect src, SDL_Rect dest)
{
    if(src.x > dest.x + dest.w || dest.x > src.x + src.w
    || src.y > dest.y + dest.h || dest.y > src.y + src.h)
        return Constants::NONE;
    
    if(src.x > dest.x && src.x + src.w < dest.x + dest.w)
        return Constants::HOR;
    
    if(src.y > dest.y && src.y + src.h < dest.y + dest.h)
        return Constants::VERT;
    
    if(src.x < dest.x)
    {
        if(src.y < dest.y)
        {
            if(src.x + src.w - dest.x < src.y + src.h - dest.y)
                return Constants::VERT;
            
            else
                return Constants::HOR;
        }
        
        else
        {
            if(src.x + src.w - dest.x < dest.y + dest.h - src.y)
                return Constants::VERT;
            
            else
                return Constants::HOR;
        }
    }
    
    else
    {
        if(src.y < dest.y)
        {
            if(dest.x + dest.w - src.x < src.y + src.h - dest.y)
                return Constants::VERT;
            
            else
                return Constants::HOR;
        }
        
        else
        {
            if(dest.x + dest.w - src.x < dest.y + dest.h - src.y)
                return Constants::VERT;
            
            else return Constants::HOR;
        }
    }
}

void ObjectManager::check_ball_brick_collision()
{
    Constants::CollisionType ct;
    
    for(std::list<Brick*>::iterator it = bricks_.begin(); it != bricks_.end(); it++)
        if(ct = rect_collision(ball_->rectangle_, (*it)->rectangle_))
        {
            it = bricks_.erase(it);
            ball_->on_collision(ct);
            
            points_ += Constants::POINTS_PER_BRICK;
        }
}

void ObjectManager::check_ball_pad_collision()
{
    int ball_left =     ball_->rectangle_.x,
        ball_right =    ball_->rectangle_.x + ball_->rectangle_.w,
        ball_top =      ball_->rectangle_.y,
        ball_bottom =   ball_->rectangle_.y + ball_->rectangle_.h,
            
        pad_left =  pad_->rectangle_.x,
        pad_right = pad_->rectangle_.x + pad_->rectangle_.w,
        pad_top =   pad_->rectangle_.y;
    
    //std::cout << ball_top << " " << ball_bottom << " " << pad_top << std::endl;
    
    if(ball_right > pad_left && ball_left < pad_right)
        if(ball_bottom > pad_top && ball_top < pad_top)
        {
            ball_->position_.setY(pad_top - Constants::BALL_WIDTH);
            
            ball_->on_pad_collision(pad_->get_velocity().getX());
        }
}
