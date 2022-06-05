//
// Created by Alexander Ivanets on 09.04.2022.
//

#include "Point.h"

float Point::getX() const {
    return this->x_;
}

float Point::getY() const {
    return this->y_;
}

float Point::getZ() const {
    return this->z_;
}

bool Point::operator==(const Point &other) const {
    return other.getX() == x_ &&
            other.getY() == y_ &&
            other.getZ() == z_;
}

bool Point::operator!=(const Point & other) const {
    return !(*this == other);
}

Vec3 *Point::operator-(const Point & other) const {
    return new Vec3(x_ - other.getX(), y_ - other.getY(), z_ - other.getZ());
}


