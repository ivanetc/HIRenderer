//
// Created by Alexander Ivanets on 09.04.2022.
//

#ifndef HIRENDER_RENDERER_H
#define HIRENDER_RENDERER_H


#include "RenderParams.h"

class Renderer {
public:
    virtual void Render(Scene, Camera, RenderParams)
};


#endif //HIRENDER_RENDERER_H
