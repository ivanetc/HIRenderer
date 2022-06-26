//
// Created by Egor on 23.06.2022.
//

#include "Plane.h"

Plane::Plane(Point orig, Vec3 norm, Material mat) : Primitive(orig, norm, mat){}

std::tuple<Point *, Vec3 *> Plane::hit(const Ray &r) const {
    Point * point = Plane::getInterception(r.direction(), r.origin());
    return std::make_tuple(point, new Vec3(this->getNormal()));
}

Point * Plane::getInterception(Vec3 vector, Point vectorOrigin) const {
        Vec3 N = this->getNormal();
        auto V = this->getOrigin() - vectorOrigin;
        // расстояние до плоскости по нормали
        auto d = Vec3::dot( N, *V );
        auto e = Vec3::dot( N, vector );
        delete V;
        if (e < 1e-6) {
            //auto p0l0 =
            auto * p = new Point(vectorOrigin + vector  * d / e ); // одна точка
            return p;
        } else {
            return nullptr;
        }
}

bool Plane::isPointOnPlane(Point p) const{
    Vec3 * v = p - getOrigin();
    float vDotPlaneNormal = Vec3::dot(*v, getNormal());
    delete v;

    return vDotPlaneNormal == 0;
}
