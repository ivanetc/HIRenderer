//
// Created by Egor on 22.05.2022.
//

#include "sphere.h"
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
    sphere(Vec3 center, float radius) : center(center), radius(radius) {};
    Point hit_sphere(const Point& center, float radius, const ray& r){
        Vec3 *oc = r.origin() - center;

        auto a = Vec3::dot(r.direction(),r.direction());
        auto b =  Vec3::dot(*oc, r.direction()) * 2.0;
        auto c = Vec3::dot(*oc, *oc) - radius*radius;
        auto discriminant = b*b - 4 * a   * c;
    };


};

Vec3 operator*(int i, const Vec3& n)
{
    return {n.getX() * i, n.getY() * i, n.getZ() * i};
}
#endif //HIRENDER_SPHERE_H