//
// Created by Egor on 22.05.2022.
//
#include "tuple"
#include "Sphere.h"
#ifndef HIRENDER_SPHERE_H
#define HIRENDER_SPHERE_H
#include "../../Math/Vec3.h"
#include "../Point.h"
#include "../../Math/ray.h"

class sphere {
private:
    Vec3 center;
    float radius;
public:


    std::tuple<Point, Vec3> hit_sphere(const Point& center, float radius, const Ray& r){
        Vec3 *oc = r.origin() - center;

        auto x = Vec3::dot(r.direction(),r.direction());
        auto y = Vec3::dot(*oc, r.direction()) * 2;
        auto z = Vec3::dot(*oc, *oc) - radius*radius;
        Point intersection = Point(x,y,z);
        return std::make_tuple(intersection,*oc);
    };


};
#endif //HIRENDER_SPHERE_H