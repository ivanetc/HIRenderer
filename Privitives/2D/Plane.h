//
// Created by Egor on 23.06.2022.
//

#ifndef HIRENDER_PLANE_H
#define HIRENDER_PLANE_H
#include "../Primitive.h"

class Plane : public Primitive{

protected:
    Point * getInterception(Vec3, Point) const;
    bool isPointOnPlane(Point p) const;

public:
    Plane(Point orig, Vec3 norm, Material mat);
    std::tuple<Point*, Vec3*> hit(const Ray& r) const override;
};


#endif //HIRENDER_PLANE_H
