/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector2D.cpp
 * Author: marcin
 * 
 * Created on 27 kwietnia 2016, 23:56
 */

#include "Vector2D.h"

Vector2D Vector2D::operator+(Vector2D v)
{
    return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator-(Vector2D v)
{
    return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::operator-()
{
    return Vector2D(-x, -y);
}

Vector2D& Vector2D::operator+=(Vector2D v)
{
    x += v.x;
    y += v.y;

    return *this;
}

Vector2D& Vector2D::operator-=(Vector2D v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

Vector2D Vector2D::operator*(double sc)
{
    return Vector2D(x * sc, y * sc);
}