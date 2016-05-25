/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marcin
 *
 * Created on 22 kwietnia 2016, 20:11
 */

#include "GameManager.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    GameManager::Instance()->init();
    
    Uint32 prev_t = SDL_GetTicks();
    Uint32 curr_t, delta;
    
    while(GameManager::Instance()->is_running())
    {
        curr_t = SDL_GetTicks();
        
        delta = curr_t - prev_t;
        
        prev_t = curr_t;
        
        GameManager::Instance()->handle_events();
        GameManager::Instance()->update(delta);
        GameManager::Instance()->render();
    }
    
    GameManager::Instance()->cleanup();
    
    return 0;
}

