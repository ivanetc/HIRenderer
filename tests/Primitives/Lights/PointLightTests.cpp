//
// Created by Alexander Ivanets on 05.06.2022.
//
#include <iostream>
#include "../../../Privitives/Lights/Light.h"
#include "../../../Privitives/Lights/PointLight.h"
#include "../../../Privitives/Lights/PointLight.cpp"
#include "../../../Privitives/Lights/Light.cpp"
#include "../../../Privitives/Point.cpp"
#include "../../../Privitives/Color.cpp"
#include "../../../Math/Vec3.cpp"


void test_lightness_calc() {
    Color color = Color(0,0,0);
    Point light_origin = {1, 2, -1};
    PointLight point_light = PointLight(light_origin, color, 100);
    Point target = {0, 0, 0};
    Vec3 normal = {0, 1, 0};

    assert(point_light.calcLightness(target, normal) == 0.541456);
    std::cout << "PointLightTests: test_lightness_calc passed " << std::endl;

}

int main() {

    test_lightness_calc();
    std::cout << "PointLightTests: tests completed successfully!" << std::endl;

    return 0;
}