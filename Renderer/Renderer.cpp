//
// Created by Alexander Ivanets on 09.04.2022.
//

#include "Renderer.h"

void Renderer::Render(Scene scene, Camera camera, RenderParams renderParams) {
    auto rays = camera.getRays();


    // static
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < rays.size(); ++i)
    {
        Ray ray = rays.at(i);
        for (Primitive* primitive : scene.getPrimitives()) {
//            primitive
            /*
             *
             * auto tuple = primitive.getIntersect(ray);
             *
             * func render(Ray, point, normal)
                 light = scene.getLights().first()
                 lightness = ligth.calcLightness(tuple.key, tuple.value)
                 color = primitive.getMaterial().color * lightness;

             *
             *
             * */
        }
    }



}
