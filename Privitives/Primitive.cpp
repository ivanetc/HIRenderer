//
// Created by Alexander Ivanets on 09.04.2022.
//

#include "Primitive.h"

Point Primitive::getOrigin() const {
    return this->origin_;
}
//
Primitive::Primitive() : origin_(0, 0, 0), normal_(0, 1, 0), material_(Material()) {

}

void Primitive::setMaterial(Material material) {
    material_ = material;
}

Vec3 Primitive::getNormal() const {
    return normal_;
}

Primitive::Primitive(Point origin, Vec3 normal, Material material) : origin_(origin), normal_(normal),
                                                                     material_(material) {}

Material Primitive::getMaterial() const {
    return material_;
}
