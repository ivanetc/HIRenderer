//
// Created by Alexander Ivanets on 23.06.2022.
//
#include <iostream>
#include "../../Privitives/3D/Sphere.cpp"
#include "../../Privitives/Point.cpp"
#include "../../Privitives/Color.cpp"
#include "../../Privitives/Primitive.cpp"
#include "../../Math/Vec3.cpp"
#include "../../Math/Ray.cpp"
#include "../../Materials/Material.cpp"
#include <cassert>
void test1();
void test2();

int main() {

    test1();
    test2();

    std::cout << "TempTest1: tests completed successfully!" << std::endl;

    return 0;
}

void test1() {
    auto sphereMaterial = Material(Color(150, 0, 24));
    auto sphere = Sphere(Point(4, 0, 0), sphereMaterial, 1);
    Ray ray = Ray(Point(), Vec3(1, 0, 0));

    auto [point, normal]  = sphere.hit(ray);

    assert(*point == Point(3, 0, 0));
    assert(*normal == Vec3(-1, 0, 0));
}

void test2() {
    auto sphereMaterial = Material(Color(150, 0, 24));
    auto sphere = Sphere(Point(4, 0, 0), sphereMaterial, 1);
    Ray ray = Ray(Point(), Vec3(-1, 0, 0));

    auto [point, normal]  = sphere.hit(ray);

    assert(point == nullptr);
    assert(normal == nullptr);
}
