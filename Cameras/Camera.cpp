//
// Created by Alexander Ivanets on 10.04.2022.
//

#include "Camera.h"


Camera::Camera(Point origin, float aspect_ratio, int image_width, float focal_length) {
    float viewport_height = 100.0;
    origin_point_ = origin;
    auto viewport_width = aspect_ratio * viewport_height;

    horizontal_ = Vec3(viewport_width, 0.0, 0.0);
    vertical_ = Vec3(0.0, viewport_height, 0.0);
    lower_left_corner_ = origin - horizontal_ / 2 - vertical_ / 2 - Vec3(0, 0, focal_length);

    image_width_ = image_width;
    image_height_ = static_cast<int>(image_width_ / aspect_ratio);
}

std::vector< std::vector <Ray>> Camera::getRays() {
    std::vector< std::vector <Ray>> rays(this->image_height_, std::vector<Ray>(this->image_width_));

    for (int j = image_height_ - 1; j >= 0; --j) {
        for (int i = 0; i < image_width_; ++i) {
            float u = float(i) / float(image_width_ - 1);
            float v = float(j) / float(image_height_ - 1);
            Vec3 * dir = lower_left_corner_ + u * horizontal_ + v * vertical_ - origin_point_;
            Ray r = Ray(origin_point_, * dir);
            rays.at(j).at(i) = r;
        }
    }

    return rays;
}

int Camera::getImageHeight() const {
    return this->image_height_;
}

int Camera::getImageWidth() const {
    return this->image_width_;
}

Point Camera::getOrigin() const {
    return this->origin_point_;
}

Camera::Camera() = default;
