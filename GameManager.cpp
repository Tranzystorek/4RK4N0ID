/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameManager.cpp
 * Author: marcin
 * 
 * Created on 3 maja 2016, 17:27
 */

#include "GameManager.h"
#include "ObjectManager.h"
#include "Pad.h"
#include "Ball.h"

#include <cstddef> //for NULL

const char* GAME_TITLE = "4RK4N0ID";

GameManager* GameManager::p_instance_ = NULL;

GameManager* GameManager::Instance()
{
    if(!p_instance_)
        p_instance_ = new GameManager();
    
    return p_instance_;
}

GameManager::GameManager()
{
    
}

bool GameManager::is_running() const
{
    return running_;
}

void GameManager::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    TTF_Init();
    
    game_window_ = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    game_renderer_ = SDL_CreateRenderer(game_window_, -1, SDL_RENDERER_ACCELERATED);
    
    
    ObjectManager::Instance(); //initialize ObjectManager
    
    running_ = true;
    
    paused_ = false;
}

void GameManager::handle_events()
{
    SDL_Event e;
    
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) )
        {
            running_ = false;
            break;
        }
        
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
            paused_ = !paused_;
        
        if(!paused_)
            ObjectManager::Instance()->handle_events(e);
    }
}

void GameManager::update(int delta)
{
    if(!paused_)
        ObjectManager::Instance()->update(delta);
}

void GameManager::render()
{
    SDL_SetRenderDrawColor(game_renderer_, 255, 255, 255, 255);
    
    SDL_RenderClear(game_renderer_);
    
    ObjectManager::Instance()->render(game_renderer_);
    
    SDL_RenderPresent(game_renderer_);
}

void GameManager::cleanup()
{
    SDL_DestroyRenderer(game_renderer_);
    
    SDL_DestroyWindow(game_window_);
    
    TTF_Quit();
    
    SDL_Quit();
}