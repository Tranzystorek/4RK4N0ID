/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector2D.h
 * Author: marcin
 *
 * Created on 27 kwietnia 2016, 23:56
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:

    Vector2D(int xx = 0, int yy = 0) : x(xx), y(yy) {};

    Vector2D operator+(Vector2D v);
    Vector2D operator-(Vector2D v);

    Vector2D& operator+=(Vector2D v);
    Vector2D& operator-=(Vector2D v);
    
    Vector2D operator*(double sc);

    Vector2D operator-();

    double getX() const {return x;}
    double getY() const {return y;}
    
    bool setX(double xx) {x = xx; return true;}
    bool setY(double yy) {y = yy; return true;}

private:
    double x;
    double y;
};

#endif /* VECTOR2D_H */

