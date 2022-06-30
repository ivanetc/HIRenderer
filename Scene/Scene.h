//
// Created by Alexander Ivanets on 10.04.2022.
//

#ifndef HIRENDER_SCENE_H
#define HIRENDER_SCENE_H


#include <vector>
#include "../Privitives/Primitive.h"
//#include <cstdlib>
#include "../Cameras/Camera/Camera.h"
#include "../Privitives/Lights/Light.h"

class Scene {
    std::vector<Primitive*> primitives_;
    std::vector<Light*> lights_;

public:
    Scene();
    std::vector<Primitive*> getPrimitives();
    void add(Primitive*);
    void add(Light*);
    std::vector<Light*> getLights();
};


#endif //HIRENDER_SCENE_H
