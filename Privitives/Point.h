//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_POINT_H
#define HIRENDER_POINT_H


#include "../Math/Vec3.h"

class Point {
    double x_;
    double y_;
    double z_;

public:
    Point(double x, double y, double z) : x_(x), y_(y), z_(z) {};

    Point operator+(Vec3);
    Point operator-(Vec3);
    bool operator==(Point);

};


#endif //HIRENDER_POINT_H
