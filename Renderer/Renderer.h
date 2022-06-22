//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_RENDERER_H
#define HIRENDER_RENDERER_H


#include "RenderParams.h"
#include "../Scene/Scene.h"
#include "../Cameras/Camera.h"

class Renderer {
    static std::tuple<Point, Vec3, Primitive*> getIntersection(Scene &scene, const Camera &camera, const Ray &ray);
public:
    static std::vector< std::vector<Color> > Render(Scene, Camera);

    static Color getRayPixelColor(Scene &scene, const Camera &camera, const Ray &ray) ;
};


#endif //HIRENDER_RENDERER_H
