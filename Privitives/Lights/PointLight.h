//
// Created by Alexander Ivanets on 22.05.2022.
//

#ifndef HIRENDER_POINTLIGHT_H
#define HIRENDER_POINTLIGHT_H


#include "Light.h"

class PointLight : Light {
public:
    PointLight(Point point, Color color, float flux) : Light(point, color, flux) {}
    double calcLightness(Point, Vec3) const override;
};


#endif //HIRENDER_POINTLIGHT_H
