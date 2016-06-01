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

Uint32 delta_time()
{
    static Uint32 prev, curr = 0;
    
    prev = curr;
    
    curr = SDL_GetTicks();
    
    return curr - prev;
}

const int FPS = 60;
const int FRAME_CAP = 1000 / FPS;

/*
 * 
 */
int main(int argc, char** argv)
{
    GameManager::Instance()->init();
    
    Uint32 delta = 0;
    
    while(GameManager::Instance()->is_running())
    {
        delta = delta_time();
        
        GameManager::Instance()->handle_events();
        GameManager::Instance()->update(delta);
        GameManager::Instance()->render();
        
        delta = delta_time();
        
        if(delta < FRAME_CAP)
            SDL_Delay(FRAME_CAP - delta);
    }
    
    GameManager::Instance()->cleanup();
    
    return 0;
}

