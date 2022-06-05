//
// Created by Alexander Ivanets on 10.04.2022.
//

#ifndef HIRENDER_CAMERA_H
#define HIRENDER_CAMERA_H


#include "../Privitives/Point.h"

class Camera {
    Point origin_point_;
    Point lower_left_corner_;
    Vec3 horizontal_;
    Vec3 vertical_;
public:
    Camera(Point origin, float aspect_ratio, float viewport_height, float focal_length);
};


#endif //HIRENDER_CAMERA_H
