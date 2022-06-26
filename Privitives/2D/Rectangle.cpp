//
// Created by Alexander Ivanets on 26.06.2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(Point orig, Vec3 norm, Material mat, int x, int y) : Plane(orig, norm, mat){
    Vec3 * x_axis = nullptr;
    Vec3 * y_axis = nullptr;

    auto new_axis = getNormal().rotate(90, 0, 0);
    if (Plane::isPointOnPlane(getOrigin() + new_axis)) {
        x_axis = new Vec3(new_axis);
    }

    new_axis = getNormal().rotate(0, 90, 0);
    if (Plane::isPointOnPlane(getOrigin() + new_axis)) {
        if (x_axis == nullptr) {
            x_axis = new Vec3(new_axis);
        } else {
            y_axis = new Vec3(new_axis);
        }
    }

    new_axis = getNormal().rotate(0, 0, 90);
    if (Plane::isPointOnPlane(getOrigin() + new_axis)) {
        y_axis = new Vec3(new_axis);
    }

    if (x_axis != nullptr && y_axis != nullptr) {
        x_ = * x_axis * x;
        y_ = * y_axis * y;
    } else {
        throw std::exception();
    }

}

std::tuple<Point *, Vec3 *> Rectangle::hit(const Ray &r) const {
    Point * point = Plane::getInterception(r.direction(), r.origin());

    if (Rectangle::isPointOnRectangle(*point)) {
        return std::make_tuple(point, new Vec3(getNormal()));
    } else {
        delete point;
        return std::make_tuple(nullptr, nullptr);
    }
}

bool Rectangle::isPointOnRectangle(Point targetPoint) const {
    Vec3 * vectorToTarget = targetPoint - getOrigin();

    auto projectionOnX = Vec3::dot(*vectorToTarget, x_) / x_.length();
    auto projectionOnY = Vec3::dot(*vectorToTarget, y_) / y_.length();

    delete vectorToTarget;

    return projectionOnX <= x_.length() && projectionOnY <= y_.length();
}



