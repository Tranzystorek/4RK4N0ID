/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.h
 * Author: marcin
 *
 * Created on 1 czerwca 2016, 02:01
 */

#include "Object.h"
#include <SDL2/SDL_ttf.h>
#include <string>

#ifndef TEXT_H
#define TEXT_H

class Text : public Object
{
public:
    
    Text(int x, int y, std::string t);
    ~Text();
    
    void render(SDL_Renderer* renderer);
    
    void set_text(std::string t);
    
    int get_width() const {return rectangle_.w;}
    
    void set_x(int x) {rectangle_.x = x;}
    
private:
    
    TTF_Font* font_;
    std::string text_;
};

#endif /* TEXT_H */

