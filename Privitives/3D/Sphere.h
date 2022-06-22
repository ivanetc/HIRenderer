#include "../../Math/Vec3.h"
#include "../Point.h"
#include "../../Math/Ray.h"
#include "tuple"
#include "../Primitive.h"


class Sphere : public Primitive {
private:
    float radius_;
public:
    Sphere(Point, Material, float);
    std::tuple<Point, Vec3> hit(const Ray& ray) const override;
};