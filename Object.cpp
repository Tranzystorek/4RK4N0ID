/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Object.cpp
 * Author: marcin
 * 
 * Created on 27 kwietnia 2016, 12:23
 */

#include "Object.h"

void Object::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
    
    SDL_RenderFillRect(renderer, &rectangle_);
}