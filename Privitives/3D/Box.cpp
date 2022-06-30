//
// Created by Alexander Ivanets on 29.06.2022.
//

#include "Box.h"
#include "vector"

std::tuple<Point *, Vec3 *> Box::hit(const Ray &ray) const {

    for (const auto& surface: surfaces_) {
        auto [point, normal] = surface.hit(ray);

        if (point != nullptr) {
            return {point, normal};
        }
    }
    return {nullptr, nullptr};
}

Box::Box(Point origin, Material material, Vec3 x, Vec3 y, Vec3 z)
    : Primitive(origin, z, material), x_(x), y_(y), z_(z) {
    auto top = Rectangle(origin + z_ * 0.5, z_, material, x_, y_);
    auto bottom = Rectangle(origin - z_ * 0.5, -z_, material, x_, y_);
    auto side1 = Rectangle(origin + x_ * 0.5, x_, material, z_, y_);
    auto side2 = Rectangle(origin - x_ * 0.5, -x_, material, z_, y_);
    auto side3 = Rectangle(origin + y_ * 0.5, y_, material, x_, z_);
    auto side4 = Rectangle(origin - y_ * 0.5, - y_, material, x_, z_);


    surfaces_.push_back(top);
    surfaces_.push_back(bottom);
    surfaces_.push_back(side1);
    surfaces_.push_back(side2);
    surfaces_.push_back(side3);
    surfaces_.push_back(side4);
}
