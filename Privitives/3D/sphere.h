//
// Created by Egor on 22.05.2022.
//

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
    bool hit_sphere(const Point& center, float radius, const ray& r){
        Vec3 *oc = r.origin() - center;
        Vec3 a = dot(r.direction(), r.direction());
//    bool hit_sphere(const point3& center, double radius, const ray& r) {
//        vec3 oc = r.origin() - center;
//        auto a = dot(r.direction(), r.direction());
//        auto b = 2.0 * dot(oc, r.direction());
//        auto c = dot(oc, oc) - radius*radius;
//        auto discriminant = b*b - 4*a*c;
//        return (discriminant > 0);
//    }
};


#endif //HIRENDER_SPHERE_H
