//
// Created by Alexander Ivanets on 10.04.2022.
//

#ifndef HIRENDER_SCENE_H
#define HIRENDER_SCENE_H


#include <vector>
#include "../Privitives/Primitive.h"
#include "stdlib.h"
#include "../Cameras/Camera.h"
#include "../Privitives/Lights/Light.h"

class Scene {
    std::vector<Primitive> primitives_;
    Camera camera_;
    std::vector<Light> lights_;

public:
    Scene();
    std::vector<Primitive> * getPrimitives();
    void add(const Primitive&);
    void add(const Light&);
    Camera * getCamera();
    std::vector<Light> * getLights();
    void setCamera(Camera camera);
};


#endif //HIRENDER_SCENE_H
