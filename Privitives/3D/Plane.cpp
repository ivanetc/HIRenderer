//
// Created by Egor on 23.06.2022.
//

#include "Plane.h"

Plane::Plane(Point orig, Vec3 norm, Material mat, int x, int y) : Primitive(orig, norm, mat) {
    this->x_ = x;
    this->y_ = y;
}

std::tuple<Point *, Vec3 *> Plane::hit(const Ray &r) const {
    Point p;
    auto denom = Vec3::dot(this->getNormal(), r.direction());
    if(denom < 0){
        return std::make_tuple(nullptr, nullptr);
    } else {
         Vec3* point = this->getOrigin() - r.direction();
         float t = Vec3::dot(point, r.direction()) / denom;
         Point* point1 = new Point(r.origin() + t * r.direction());
         Vec3 *vecResult = new Vec3(this->getNormal());

         return std::tuple<Point *, Vec3 *>();
    }
}
