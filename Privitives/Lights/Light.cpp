//
// Created by Alexander Ivanets on 22.05.2022.
//

#include "Light.h"

Light::Light(Point originalPoint, Color color, float actualFlux) :
    originalPoint_(originalPoint), color_(color), actualFlux_(actualFlux) {}

Point Light::getOriginalPoint() const {
    return originalPoint_;
}

Color Light::getColor() const {
    return color_;
}

float Light::getActualFlux() const {
    return actualFlux_;
}

