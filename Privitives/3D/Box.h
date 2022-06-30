//
// Created by Alexander Ivanets on 29.06.2022.
//

#ifndef HIRENDER_BOX_H
#define HIRENDER_BOX_H


#include <vector>
#include "../Primitive.h"
#include "../2D/Rectangle.h"

class Box : public Primitive {
    Vec3 x_;
    Vec3 y_;
    Vec3 z_;
    std::vector<Rectangle> surfaces_;

public:
    Box(Point, Material, Vec3, Vec3, Vec3);
    std::tuple<Point*, Vec3*> hit(const Ray& ray) const override;
};


#endif //HIRENDER_BOX_H
