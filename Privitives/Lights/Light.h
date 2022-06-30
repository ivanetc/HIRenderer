//
// Created by Alexander Ivanets on 22.05.2022.
//

#ifndef HIRENDER_LIGHT_H
#define HIRENDER_LIGHT_H


#include "../Point.h"
#include "../../Materials/Color.h"

class Light {
    Point originalPoint_;
    Color color_;
    float actualFlux_;

public:
    Light(Point, Color, float);
    Point getOriginalPoint() const;
    Color getColor() const;
    float getActualFlux() const;
    virtual double calcLightness(Point, Vec3) const = 0;
};


#endif //HIRENDER_LIGHT_H
