//
// Created by Alexander Ivanets on 10.04.2022.
//

#include <iostream>
#include <cassert>
#include "../../../Math/Vec3.h"

void operator_plus_test() {
    Vec3 vec1 = Vec3(1, 2, 3);
    Vec3 vec2 = Vec3(10, 20, 30);

    Vec3 result_vec = vec1 + vec2;
    assert(result_vec.getX() == 11);
    assert(result_vec.getY() == 22);
    assert(result_vec.getZ() == 33);
}

void operator_minus_test() {
    Vec3 vec1 = Vec3(1, 2, 3);
    Vec3 vec2 = Vec3(10, 20, 30);

    Vec3 result_vec = vec2 - vec1;
    assert(result_vec.getX() == 9);
    assert(result_vec.getY() == 18);
    assert(result_vec.getZ() == 17);
}

void operator_multiply_test() {
    Vec3 vec1 = Vec3(2, 3, 4);
    Vec3 vec2 = Vec3(10, 20, 30);

    Vec3 result_vec = vec2 * vec1;
    assert(result_vec.getX() == 20);
    assert(result_vec.getY() == 60);
    assert(result_vec.getZ() == 120);
}

int main() {

    operator_minus_test();
    operator_plus_test();
    operator_multiply_test();
    std::cout << "Vec3OperatorsTests: tests completed successfully!" << std::endl;

    return 0;
}
