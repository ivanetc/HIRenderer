//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_POINT_H
#define HIRENDER_POINT_H


#include "../Math/Vec3.h"

class Point {
    float x_;
    float y_;
    float z_;

public:
    Point() : x_(0), y_(0), z_(0) {};
    Point(float x, float y, float z) : x_(x), y_(y), z_(z) {};

    float getX() const;
    float getY() const;
    float getZ() const;

    bool operator==(const Point&) const;
    bool operator!=(const Point&) const;
    Vec3 * operator-(const Point&) const;
    Point operator+(const Vec3&) const;
    Point operator-(const Vec3&) const;
};


#endif //HIRENDER_POINT_H