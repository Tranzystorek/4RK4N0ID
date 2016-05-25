/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameManager.h
 * Author: marcin
 *
 * Created on 3 maja 2016, 17:27
 */

#include <SDL2/SDL.h>

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager
{
public:
    static GameManager* Instance();
    
    void init();
    void handle_events();
    void update(int delta);
    void render();
    void cleanup();
    
    bool is_running() const;
    
private:
    GameManager();
    
    static GameManager* p_instance_;
    
    bool running_;
    
    SDL_Window* game_window_;
    SDL_Renderer* game_renderer_;
};

#endif /* GAMEMANAGER_H */

