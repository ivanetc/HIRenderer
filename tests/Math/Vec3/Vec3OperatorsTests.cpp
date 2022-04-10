//
// Created by Alexander Ivanets on 10.04.2022.
//

#include <iostream>
#include <cassert>
#include "../../../Math/Vec3.h"
#include "../../../Math/Vec3.cpp"

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
    assert(result_vec.getZ() == 27);
}

void operator_multiply_test() {
    Vec3 vec1 = Vec3(2, 3, 4);
    Vec3 vec2 = Vec3(10, 20, 30);

    Vec3 result_vec = vec2 * vec1;
    assert(result_vec.getX() == 20);
    assert(result_vec.getY() == 60);
    assert(result_vec.getZ() == 120);
}

void operator_negative_test(){
    Vec3 vec = Vec3(5,5,5);
    Vec3 result_vec = -vec;
    assert(result_vec.getX() == -5);
    assert(result_vec.getY() == -5);
    assert(result_vec.getZ() == -5);
}

void bool_test(){
    Vec3 original_vec = Vec3(1,2,3);
    Vec3 vec1 = original_vec;
    Vec3 vec2 = original_vec;
    assert(vec1.getX() == vec2.getX());
    assert(vec1.getY() == vec2.getY());
    assert(vec1.getZ() == vec2.getZ());
    assert(vec1 == vec2);
    assert(original_vec == vec1);
    assert(original_vec == vec2);

    std::cout << "Vec3OperatorsTests: bool_test completed" << std::endl;

}

int main() {

    operator_minus_test();
    operator_plus_test();
    operator_multiply_test();
    operator_negative_test();
    bool_test();
    std::cout << "Vec3OperatorsTests: tests completed successfully!" << std::endl;

    return 0;
}
