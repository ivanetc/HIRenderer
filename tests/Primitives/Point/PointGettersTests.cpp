//
// Created by Alexander Ivanets on 10.04.2022.
//

#include <iostream>
#include <cassert>
#include "../../../Privitives/Point.h"
#include "../../../Privitives/Point.cpp"
#include "../../../Math/Vec3.cpp"

void coordinates_getters() {
    Point point = Point(0, 1, 2);
    assert(point.getX() == 0);
    assert(point.getY() == 1);
    assert(point.getZ() == 2);
}

void immutable_getters() {
    Point point = Point(0, 1, 2);
    auto x = point.getX();
    x++;

    assert(point.getX() == 0);
}

int main() {
    coordinates_getters();
    immutable_getters();
    std::cout << "PointGettersTests: tests completed successfully!" << std::endl;

    return 0;
}

