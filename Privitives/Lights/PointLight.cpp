//
// Created by Alexander Ivanets on 22.05.2022.
//

#include "PointLight.h"
#include <math.h>
#include <iostream>

static double toRad(double degree) {
    return degree * M_PI / 180;
}

static double getAngleCos(Vec3 * vec1, Vec3 * vec2) {
    double scalarMultiply = vec1->getX() * vec2->getX() + vec1->getY() * vec2->getY() + vec1->getZ() * vec2->getZ();
    double lengthMultiply = vec1->length() * vec2->length();
    return scalarMultiply / lengthMultiply;
}

double PointLight::calcLightness(Point point, Vec3 normalVector) const {
    Vec3 * vecToLight = this->getOriginalPoint() - point;

    double angleCos = getAngleCos(&normalVector, vecToLight);
    double I = this->getActualFlux() / (4 * M_PI);
    double E = I * angleCos / pow(vecToLight->length(), 2);

    delete vecToLight;
    return E;
}
