//
// Created by Alexander Ivanets on 09.04.2022.
//

#include "Material.h"

Material::Material() = default;

Material::Material(Color color) : color_(color) {}

Color Material::getColor() const {
    return this->color_;
}
