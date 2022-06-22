//
// Created by Alexander Ivanets on 09.04.2022.
//

#include "Renderer.h"

void Renderer::Render(Scene scene, Camera camera, RenderParams renderParams) {
    auto rays = camera.getRays();

    for (Ray ray : rays) // перебираем массив fibonacci
    {

        for (Primitive primitive : *scene.getPrimitives()) {
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
