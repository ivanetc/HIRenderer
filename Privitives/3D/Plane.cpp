//
// Created by Egor on 23.06.2022.
//

#include "Plane.h"

Plane::Plane(Point orig, Vec3 norm, Material mat, int x, int y) : Primitive(orig, norm, mat), x_(x), y_(y) {}

std::tuple<Point *, Vec3 *> Plane::hit(const Ray &r) const {
    Point p;
    auto denom = Vec3::dot(this->getNormal(), r.direction());
    if (denom >= 0) {
        Vec3* v = this->getOrigin() - r.origin();
        float t = Vec3::dot(*v, r.direction()) / denom;
        delete v;

        if (t > 0) {
            auto* point1 = new Point(r.origin() + t * r.direction());
            Vec3 *vecResult = new Vec3(this->getNormal());

            return std::make_tuple(point1, vecResult);
        }
    }

    return std::make_tuple(nullptr, nullptr);
}
