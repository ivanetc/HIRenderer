//
// Created by Alexander Ivanets on 10.04.2022.
//

#ifndef HIRENDER_CAMERA_H
#define HIRENDER_CAMERA_H

#include <vector>

#include "../Privitives/Point.h"
#include "../Math/Ray.h"

class Camera {
    int image_height_;
    int image_width_;
    Point origin_point_;
    Point lower_left_corner_;
    Vec3 horizontal_;
    Vec3 vertical_;
public:
    Camera(Point origin, float aspect_ratio, int image_width, float focal_length);
    std::vector<Ray> getRays();
};


#endif //HIRENDER_CAMERA_H
