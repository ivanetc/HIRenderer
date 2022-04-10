//
// Created by Alexander Ivanets on 10.04.2022.
//

#include <iostream>
#include "../Math/Vec3.h"
#include <cassert>

void test1() {
    int a = 1;
    int b = 2;
    assert(a + b == 3);

}
void test2(){
    int a = 5;
    int b = 2;
    assert(a - b == 3);
}

void test3(){
    int a = 5;
    int b = 5;
    assert(a * b == 25);
}

void test4(){
    int a = 10;
    assert(a + NULL == 10);
}

void test5(){
    int a = 10;
    assert(a * NULL == 0);
}

void test6(){
    int a = 11;
    assert(a - NULL == 11);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    std::cout << "TempTest1: tests completed successfully!" << std::endl;

    return 0;
}

