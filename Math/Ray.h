//
// Created by Egor on 22.05.2022.
//

#ifndef HIRENDER_RAY_H
#define HIRENDER_RAY_H

#include "Vec3.h"
#include "../Privitives/Point.h"

class Ray {
public:
    Point orig;
    Vec3 dir;
    Ray(const Point& origin, const Vec3 direction) : orig(origin), dir(direction){}

    Point origin() const{
        return orig;
    }
    Vec3 direction() const{
        return dir;
    }

    Point at(float t) {
        return orig + dir * t;
    }
};


#endif //HIRENDER_RAY_H
