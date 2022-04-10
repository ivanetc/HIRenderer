//
// Created by Alexander Ivanets on 10.04.2022.
//

#include <iostream>

void test1() {
    int a = 1;
    int b = 2;
    assert(a + b == 3);
}

int main() {
    test1();

    std::cout << "TempTest1: tests completed successfully!" << std::endl;

    return 0;
}

