//
// Created by Alexander Ivanets on 26.06.2022.
//

#include "Rectangle.h"
#include <exception>

Rectangle::Rectangle(Point orig, Vec3 norm, Material mat, double x, double y) : Plane(orig, norm, mat){
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
        x_ = * x_axis * (x / x_axis->length());
        y_ = * y_axis * (y / y_axis->length());
    } else {
        throw std::exception();
    }

}

std::tuple<Point *, Vec3 *> Rectangle::hit(const Ray &r) const {
    Point * point = Plane::getInterception(r.direction(), r.origin());

    if (point != nullptr) {
        if (Rectangle::isPointOnRectangle(*point)) {
            return std::make_tuple(point, new Vec3(getNormal()));
        } else {
            delete point;
        }
    }
    return std::make_tuple(nullptr, nullptr);
}

bool Rectangle::isPointOnRectangle(Point targetPoint) const {
    Vec3 ab = y_;
    Vec3 bc = x_;
    Point b = getOrigin();
    Vec3 * am = targetPoint - (b - ab);
    Vec3 * bm = targetPoint - b;

    auto dotAbAm = Vec3::dot(ab, *am);
    auto dotAbAb = Vec3::dot(ab, ab);
    auto dotBcBm = Vec3::dot(bc, *bm);
    auto dotBcBc = Vec3::dot(bc, bc);

    delete bm;
    delete am;

    return dotAbAm >= 0 && dotAbAm <= dotAbAb && dotBcBm >= 0 && dotBcBm <= dotBcBc;
}



