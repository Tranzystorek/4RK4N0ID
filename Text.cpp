/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.cpp
 * Author: marcin
 * 
 * Created on 1 czerwca 2016, 02:01
 */

#include "Text.h"

Text::Text(int x, int y, std::string t) : text_(t)
{
    font_ = TTF_OpenFont("/usr/share/fonts/TTF/LiberationSans-Regular.ttf", Constants::FONT_SIZE);
    
    rectangle_.x = x;
    rectangle_.y = y;
}

Text::~Text()
{
    TTF_CloseFont(font_);
}

void Text::render(SDL_Renderer* renderer)
{
    SDL_Surface* s = TTF_RenderText_Shaded(font_, text_.c_str(), Constants::BLACK, Constants::MELLOW);
    
    rectangle_.w = s->w;
    rectangle_.h = s->h;
    
    SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);
    
    SDL_RenderCopy(renderer, t, NULL, &rectangle_);
    
    SDL_DestroyTexture(t);
    SDL_FreeSurface(s);
}

void Text::set_text(std::string t)
{
    text_ = t;
}