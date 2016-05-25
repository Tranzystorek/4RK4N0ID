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
    
    game_window_ = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    game_renderer_ = SDL_CreateRenderer(game_window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    
    ObjectManager::Instance(); //initialize ObjectManager
    
    running_ = true;
}

void GameManager::handle_events()
{
    SDL_Event e;
    
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
        {
            running_ = false;
            break;
        }
        
        ObjectManager::Instance()->handle_events(e);
    }
}

void GameManager::update(int delta)
{
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
    
    SDL_Quit();
}