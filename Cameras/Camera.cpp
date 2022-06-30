//
// Created by Alexander Ivanets on 10.04.2022.
//

#include <random>
#include "Camera.h"

float random(float from, float to) {
    std::random_device rd;
    std::mt19937_64 e10(rd());
    std::uniform_real_distribution<> dist(from, to);
    return dist(e10);
}

Camera::Camera(Point origin, float aspect_ratio, int image_width, float focal_length) {
    float viewport_height = 100.0;
    origin_point_ = origin;
    viewport_height_ = viewport_height;
    viewport_width_ = aspect_ratio * viewport_height;

    horizontal_ = Vec3(viewport_width_, 0.0, 0.0);
    vertical_ = Vec3(0.0, viewport_height, 0.0);
    lower_left_corner_ = origin - horizontal_ / 2 - vertical_ / 2 - Vec3(0, 0, focal_length);

    image_width_ = image_width;
    image_height_ = static_cast<int>(image_width_ / aspect_ratio);
    samplesPerPixel = 4;
}

std::vector< std::vector <PixelRayCollection>> Camera::getRays() {
    std::vector< std::vector <PixelRayCollection>> rays(this->image_height_, std::vector<PixelRayCollection>(this->image_width_));

    float pixel_viewport_half_width = viewport_width_ / (2 * image_width_);
    float pixel_viewport_half_height = viewport_height_ / (2 * image_height_);

    for (int j = image_height_ - 1; j >= 0; --j) {
        for (int i = 0; i < image_width_; ++i) {
            float u = float(i) / float(image_width_ - 1);
            float v = float(j) / float(image_height_ - 1);
            auto rayCollection = PixelRayCollection();

            for(int s = 0; s < samplesPerPixel; s++) {
                auto rand_width_movement = random(- pixel_viewport_half_width, pixel_viewport_half_width);
                auto rand_height_movement = random(- pixel_viewport_half_height, pixel_viewport_half_height);
                Point pixel_center = lower_left_corner_ + u * horizontal_ + v * vertical_;
                pixel_center.setX(pixel_center.getX() + rand_width_movement);
                pixel_center.setY(pixel_center.getY() + rand_height_movement);

                Vec3 * dir = pixel_center - origin_point_;
                Ray r = Ray(origin_point_, * dir);

                rayCollection.rays.push_back(r);
            }
            rays.at(j).at(i) = rayCollection;
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
