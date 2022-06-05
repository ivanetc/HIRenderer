//
// Created by Alexander Ivanets on 16.04.2022.
//
#include <cassert>
#include <iostream>
#include "../../../Privitives/Point.h"
#include "../../../Privitives/Point.cpp"
#include "../../../Math/Vec3.h"
#include "../../../Math/Vec3.cpp"

void assigment_operator_test() {
    Point point1 = Point(1, 1, 1);
    Point point2 = Point(2, 2, 2);

    point1 = point2;
    assert(point1.getX() == 2);
    assert(point1.getY() == 2);
    assert(point1.getZ() == 2);

}

void equal_operator_test() {
    Point point1 = Point(1, 1, 1);
    Point point2 = Point(1, 1, 1);

    assert(point1 == point2);
}

void equal_operator_null_test() {
    Point * point1 = nullptr;
    Point * point2 = nullptr;
    Point * point3 = new Point(1, 1, 1);

    assert(point1 == point2);
    assert(point1 != point3);

    delete point1;
    delete point2;
    delete point3;
}

void unequal_operator_test() {
    Point point1 = Point(1, 1, 1);
    Point point2 = Point(2, 1, 1);

    assert(point1 != point2);
}

void subtraction_operator_test() {
    Point point1 = Point(5, 4, 3);
    Point point2 = Point(1, 2, 3);
    Vec3 * vec = point1 - point2;
    assert(vec->getX() == 4);
    assert(vec->getY() == 2);
    assert(vec->getZ() == 0);

    delete vec;
}

int main() {
    assigment_operator_test();
    equal_operator_test();
    unequal_operator_test();
    equal_operator_null_test();
    subtraction_operator_test();
    std::cout << "PointOperatorsTests: tests completed successfully!" << std::endl;

    return 0;
}