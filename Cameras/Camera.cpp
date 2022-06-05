//
// Created by Alexander Ivanets on 10.04.2022.
//

#include "Camera.h"


Camera::Camera(Point origin, float aspect_ratio, float viewport_height, float focal_length) {
    origin_point_ = origin;
    auto viewport_width = aspect_ratio * viewport_height;

    horizontal_ = Vec3(viewport_width, 0.0, 0.0);
    vertical_ = Vec3(0.0, viewport_height, 0.0);
    lower_left_corner_ = origin - horizontal_ / 2 - vertical_ / 2 - Vec3(0, 0, focal_length);
}
