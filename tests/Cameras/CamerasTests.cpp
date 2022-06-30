//
// Created by Alexander Ivanets on 23.06.2022.
//
#include <iostream>
#include <cassert>
#include "../../Cameras/Camera/Camera.h"
#include "../../Cameras/Camera/Camera.cpp"
#include "../../Cameras/Ray/Ray.cpp"
#include "../../Math/Vec3.cpp"
#include "../../Privitives/Point.cpp"

int main() {

    Camera camera = Camera(
            Point(0, 0,0),
            16.0/9,
            1280,
            2
            );
    assert(camera.getImageHeight() == 720);
    auto rays = camera.getRays();

    assert(rays.size() == camera.getImageHeight());
    assert(rays.at(0).size() == camera.getImageWidth());

    std::cout << "Cameras: tests completed successfully!" << std::endl;

    return 0;
}
