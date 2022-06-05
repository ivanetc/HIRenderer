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
    std::cout <<  "Vec3OperatorsTest_1: operator_minus_test completed" << std::endl;
}

void operator_minus_test() {
    Vec3 vec1 = Vec3(1, 2, 3);
    Vec3 vec2 = Vec3(10, 20, 30);

    Vec3 result_vec = vec2 - vec1;
    assert(result_vec.getX() == 9);
    assert(result_vec.getY() == 18);
    assert(result_vec.getZ() == 27);
    std::cout << "Vec3OperatorsTest_2: operator_plus_test completed" << std::endl;
}

void operator_multiply_test() {
    Vec3 vec1 = Vec3(2, 3, 4);
    Vec3 vec2 = Vec3(10, 20, 30);
    Vec3 result_vec = vec2 * vec1;
    assert(result_vec.getX() == 20);
    assert(result_vec.getY() == 60);
    assert(result_vec.getZ() == 120);
    std::cout << "Vec3OperatorsTest_3: operator_multiply_test completed" << std::endl;
}

void operator_negative_test(){
    Vec3 vec = Vec3(5,5,5);
    Vec3 result_vec = -vec;
    assert(result_vec.getX() == -5);
    assert(result_vec.getY() == -5);
    assert(result_vec.getZ() == -5);
    std::cout << "Vec3OperatorsTest_4: operator_negative_test completed" << std::endl;
}

void bool_test(){
    Vec3 original_vec = Vec3(1,2,3);
    Vec3 vec1 = Vec3(0,0,0);
    vec1 = original_vec;
    assert(vec1.getX() == original_vec.getX());
    assert(vec1.getY() == original_vec.getY());
    assert(vec1.getZ() == original_vec.getZ());
    std::cout << "Vec3OperatorsTest_5: bool_test completed" << std::endl;
}

void length_test(){
    Vec3 vec = Vec3(2,4,4);
    assert(vec.length() == 6);
    std::cout << "Vec3OperatorsTest_5: length_test completed" << std::endl;
}

void all_operators_test(){
    Vec3 vec1 = Vec3(1,1,1);
    Vec3 vec2 = Vec3(2,2,2);
    Vec3 vec3 = Vec3(3,3,3);
    Vec3 result_vec = (vec3 + vec2 - vec1) * vec1;
    assert(result_vec.getX() == 4);
    assert(result_vec.getY() == 4);
    assert(result_vec.getZ() == 4);
    std::cout << "Vec3OperatorsTest_6: all_operators_test completed" << std::endl;
}

int main() {

    operator_plus_test();
    operator_minus_test();
    operator_multiply_test();
    operator_negative_test();
    bool_test();
    length_test();
    all_operators_test();
    std::cout << "Vec3OperatorsTests: tests completed successfully!" << std::endl;


    return 0;
}
