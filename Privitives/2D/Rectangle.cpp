//
// Created by Alexander Ivanets on 26.06.2022.
//

#include "Rectangle.h"
#include <exception>

Rectangle::Rectangle(Point orig, Vec3 norm, Material mat, Vec3 x, Vec3 y) : Plane(orig, norm, mat), x_(x), y_(y) {
    this->setOrigin(getOrigin() - x * 0.5 + y * 0.5);
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



