//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_PRIMITIVE_H
#define HIRENDER_PRIMITIVE_H


#include "../Materials/Material.h"
#include "Point.h"

class Primitive {
    Point origin_;
    Vec3 normal_;
    Material * material_;

public:
    Primitive();
    Point getOrigin() const;
    Vec3 getNormal() const;

    virtual void setMaterial(Material *);
};



#endif //HIRENDER_PRIMITIVE_H