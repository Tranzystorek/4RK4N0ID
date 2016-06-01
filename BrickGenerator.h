/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BrickGenerator.h
 * Author: marcin
 *
 * Created on 31 maja 2016, 22:12
 */

#include "Brick.h"

#ifndef BRICKGENERATOR_H
#define BRICKGENERATOR_H

class BrickGenerator
{
public:
    
    BrickGenerator();
    
    Brick* generate_brick();
    
private:
    
    int row_;
    int column_;
    
    bool done_;
};

#endif /* BRICKGENERATOR_H */

