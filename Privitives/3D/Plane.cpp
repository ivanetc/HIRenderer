//
// Created by Egor on 23.06.2022.
//

#include "Plane.h"

Plane::Plane(Point orig, Vec3 norm, Material mat, int x, int y) : Primitive(orig, norm, mat), x_(x), y_(y) {}

std::tuple<Point *, Vec3 *> Plane::hit(const Ray &r) const {
//    Point p;
//    auto denom = Vec3::dot(this->getNormal(), r.direction());
//    if (denom >= 0) {
//        Vec3* v = this->getOrigin() - r.origin();
//        float t = Vec3::dot(*v, r.direction()) / denom;
//        delete v;
//
//        if (t < 0) {
//            auto* point1 = new Point(r.origin() + t * r.direction());
//            Vec3 *vecResult = new Vec3(this->getNormal());
//
//            return std::make_tuple(point1, vecResult);
//        }
//    }
    Point * point = Plane::getInterception(r);
    return std::make_tuple(point, new Vec3(this->getNormal()));
//    Vec3 N = this->getNormal();
//    auto V = this->getOrigin() - r.origin();
//    // расстояние до плоскости по нормали
//    auto d = Vec3::dot( N, *V );
//    auto e = Vec3::dot( N, r.direction() );
//
//    delete V;
//    if (e < 1e-6) {
//        //auto p0l0 =
//       auto * p = new Point(r.origin() + r.direction()  * d / e ); // одна точка
//        return std::make_tuple(p, new Vec3(N));
//    } else {
//        return std::make_tuple(nullptr, nullptr);
//    }
}

Point * Plane::getInterception(Ray r) const {
        Vec3 N = this->getNormal();
        auto V = this->getOrigin() - r.origin();
        // расстояние до плоскости по нормали
        auto d = Vec3::dot( N, *V );
        auto e = Vec3::dot( N, r.direction() );
        delete V;
        if (e < 1e-6) {
            //auto p0l0 =
            auto * p = new Point(r.origin() + r.direction()  * d / e ); // одна точка
            return p;
        } else {
            return nullptr;
        }
}
