//
// Created by Alexander Ivanets on 26.06.2022.
//

#ifndef HIRENDER_RECTANGLE_H
#define HIRENDER_RECTANGLE_H
#include "Plane.h"

class Rectangle : public Plane {
    Vec3 x_;
    Vec3 y_;
    bool isPointOnRectangle(Point) const;

public:
    Rectangle(Point orig, Vec3 norm, Material mat, int x, int y);
    std::tuple<Point*, Vec3*> hit(const Ray& r) const override;
};


#endif //HIRENDER_RECTANGLE_H
