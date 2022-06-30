//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_PRIMITIVE_H
#define HIRENDER_PRIMITIVE_H
#include "tuple"


#include "../Materials/Material.h"
#include "Point.h"
#include "../Cameras/Ray/Ray.h"

class Primitive {
    Point origin_;
    Vec3 normal_;
    Material material_;
protected:
    void setOrigin(Point);
public:
    Primitive();
    Primitive(Point, Vec3, Material);
    Point getOrigin() const;
    Vec3 getNormal() const;

    Material getMaterial() const;
    void setMaterial(Material);
    virtual std::tuple<Point*, Vec3*> hit(const Ray& r) const = 0;
};



#endif //HIRENDER_PRIMITIVE_H