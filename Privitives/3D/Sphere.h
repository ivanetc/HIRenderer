#include "../../Math/Vec3.h"
#include "../Point.h"
#include "../../Cameras/Ray/Ray.h"
#include "tuple"
#include "../Primitive.h"


class Sphere : public Primitive {
private:
    float radius_;
public:
    Sphere(Point, Material, float);
    std::tuple<Point*, Vec3*> hit(const Ray& ray) const override;

    static std::tuple<float, float> getQuadraticSolution(float a, float d, float c, float descriminant) ;
};