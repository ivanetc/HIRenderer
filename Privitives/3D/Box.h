//
// Created by Alexander Ivanets on 29.06.2022.
//

#ifndef HIRENDER_BOX_H
#define HIRENDER_BOX_H


#include <vector>
#include "../Primitive.h"
#include "../2D/Rectangle.h"

class Box : public Primitive {
    std::vector<Rectangle> surfaces_;

public:
    Box(Point, Vec3, Material, float);
    std::tuple<Point*, Vec3*> hit(const Ray& ray) const override;
};


#endif //HIRENDER_BOX_H
