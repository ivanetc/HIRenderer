//
// Created by Alexander Ivanets on 29.06.2022.
//

#include "Box.h"
#include "vector"

Box::Box(Point origin, Vec3 norm, Material material, float side_size) : Primitive(origin, norm, material) {
    auto top = Rectangle(origin, norm, material, side_size, side_size);
    auto bottom = Rectangle(origin - norm, - norm, material, side_size, side_size);

    auto side_norm = norm.rotate(90, 0, 0);
    auto side1 = Rectangle(origin, side_norm, material, side_size, side_size);

    surfaces_.push_back(top);
    surfaces_.push_back(bottom);
    surfaces_.push_back(side1);
}

std::tuple<Point *, Vec3 *> Box::hit(const Ray &ray) const {

    for (const auto& surface: surfaces_) {
        auto [point, normal] = surface.hit(ray);

        if (point != nullptr) {
            return {point, normal};
        }
    }
    return {nullptr, nullptr};
}
