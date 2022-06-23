//
// Created by Egor on 23.06.2022.
//

#ifndef HIRENDER_PLANE_H
#define HIRENDER_PLANE_H
#include "../Primitive.h"

class Plane : public Primitive{
    int x_;
    int y_;
public:
    Plane(Point orig, Vec3 norm, Material mat, int x, int y);
    std::tuple<Point*, Vec3*> hit(const Ray& r) const;
};


#endif //HIRENDER_PLANE_H
