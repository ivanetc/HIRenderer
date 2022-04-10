//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_RENDERER_H
#define HIRENDER_RENDERER_H


#include "RenderParams.h"
#include "../Scene/Scene.h"
#include "../Cameras/Camera.h"

class Renderer {
public:
    virtual void Render(Scene, Camera, RenderParams);
};


#endif //HIRENDER_RENDERER_H
