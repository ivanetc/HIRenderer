//
// Created by Egor on 22.05.2022.
//
#include "tuple"
#include "Sphere.h"
#ifndef HIRENDER_SPHERE_H
#define HIRENDER_SPHERE_H
#include "../../Math/Vec3.h"
#include "../Point.h"


#endif //HIRENDER_SPHERE_H

Sphere::Sphere(Point origin, Material material, float radius) : Primitive(origin, Vec3(), material) {
    this->radius_ = radius;
}

std::tuple<Point, Vec3> Sphere::hit(const Ray &ray) const {
        Vec3* oc = ray.origin() - getOrigin();

        auto x = Vec3::dot(ray.direction(), ray.direction());
        auto y = Vec3::dot(*oc, ray.direction()) * 2;
        auto z = Vec3::dot(*oc, *oc) - radius_ * radius_;
        Point intersection = Point(x,y,z);
        return std::make_tuple(intersection,*oc);

}
