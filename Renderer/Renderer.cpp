//
// Created by Alexander Ivanets on 09.04.2022.
//

#include "Renderer.h"
#include <iostream>


std::vector< std::vector<Color> > Renderer::Render(Scene scene, Camera camera) {
    auto rays = camera.getRays();

    int imageHeight = camera.getImageHeight();
    int imageWidth = camera.getImageWidth();
    std::vector< std::vector<Color> > pixels (imageHeight, std::vector<Color> (imageWidth));
    // static
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < rays.size(); i++)
    {
        for (int j = 0; j < rays.at(i).size(); j++) {
            Ray ray = rays.at(i).at(j);
            Color currentPixelColor = getRayPixelColor(scene, camera, ray);
            pixels.at(i).at(j) = currentPixelColor;
        }
    }
    return pixels;
}

Color Renderer::getRayPixelColor(Scene &scene, const Camera &camera, const Ray &ray) {
    Color currentPixelColor;

    auto [intersectionPoint, intersectionPointNormal, closestPrimitive] = getIntersection(scene, camera, ray);
    if (intersectionPoint != nullptr) {
        Light * mainLight = scene.getLights().at(0);

        // check light ray intersection with other primitives
        //Point mainLightOrigin = mainLight->getOriginalPoint();
        //Vec3 * rayFromLightDir = mainLightOrigin - *intersectionPoint;
        //Ray rayFromLight = Ray(mainLightOrigin, *rayFromLightDir);
        //auto [p, n, intersectedPrimitive] = getIntersection(scene, camera, rayFromLight);
        //if (intersectedPrimitive == closestPrimitive || intersectedPrimitive == nullptr) {

            // if our point on primitive, intersected with ray from camera and ray from light
            // we will calculate lightness on it
            double lightness = mainLight->calcLightness(*intersectionPoint, *intersectionPointNormal);

            currentPixelColor = closestPrimitive->getMaterial().getColor() * lightness;
        //}

//        delete rayFromLightDir;
    }
    delete intersectionPoint;
    delete intersectionPointNormal;

    return currentPixelColor;
}

std::tuple<Point*, Vec3*, Primitive *> Renderer::getIntersection(Scene &scene, const Camera &camera, const Ray &ray) {
    Point * intersectionPoint = nullptr;
    Vec3 * intersectionPointNormal = nullptr;
    Primitive * closestPrimitive = nullptr;

    for (Primitive* primitive : scene.getPrimitives()) {
        auto [primitiveIntersectionPoint, primitiveNormal] = primitive->hit(ray);

        if (primitiveIntersectionPoint != nullptr) {
            if (intersectionPoint == nullptr || primitiveIntersectionPoint->isCloserToOrigin(camera.getOrigin(), *intersectionPoint)) {
                intersectionPoint = primitiveIntersectionPoint;
                intersectionPointNormal = primitiveNormal;
                closestPrimitive = primitive;
            } else {
                delete primitiveIntersectionPoint;
                delete primitiveNormal;
            }
        }

    }

    return std::make_tuple(intersectionPoint, intersectionPointNormal, closestPrimitive);
}
