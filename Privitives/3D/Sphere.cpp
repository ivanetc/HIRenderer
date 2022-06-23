//
// Created by Egor on 22.05.2022.
//
#include <cmath>
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

std::tuple<Point*, Vec3*> Sphere::hit(const Ray &ray) const {
        Vec3* oc = ray.origin() - getOrigin();

        auto a = Vec3::dot(ray.direction(), ray.direction());
        auto b = Vec3::dot(*oc, ray.direction()) * 2;
        auto c = Vec3::dot(*oc, *oc) - radius_ * radius_;

        auto descriminant = b * b - 4*a*c;

        if (descriminant < 0) {
            return std::make_tuple(nullptr, nullptr);
        } else {
            auto[t1, t2] = getQuadraticSolution(a, b, c, descriminant);

            Point * point1Ptr = nullptr;
            Point * point2Ptr = nullptr;
            if (t1 > 0) {
                point1Ptr = new Point(ray.origin() + t1 * ray.direction());
            }
            if (t2 > 0) {
                point2Ptr = new Point(ray.origin() + t2 * ray.direction());
            }

            if (point1Ptr == nullptr) {
                if (point2Ptr == nullptr) {
                    return std::make_tuple(nullptr, nullptr);
                } else {
                    return std::make_tuple(point2Ptr, *point2Ptr - getOrigin());
                }
            } else if (point2Ptr == nullptr) {
                    return std::make_tuple(point1Ptr, *point1Ptr - getOrigin());

            } else {
                if (point1Ptr->isCloserToOrigin(ray.origin(), *point2Ptr)) {
                    delete point2Ptr;
                    return std::make_tuple(point1Ptr, *point1Ptr - getOrigin());
                } else {
                    delete point1Ptr;
                    return std::make_tuple(point2Ptr, *point2Ptr - getOrigin());
                }
            }
        }
}

std::tuple<float, float> Sphere::getQuadraticSolution(float a, float b, float c, float d) {
    double q = b >= 0 ? (-b - sqrt(d)) / 2  : (-b + sqrt(d)) / 2;

    double x1 = q / a;
    double x2 = c / q;

    return std::make_tuple(x1, x2);
}
