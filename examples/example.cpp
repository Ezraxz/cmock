#include <iostream>
#include <cmath>
#include "cmock.h"

MOCK_TEST_P1(abs, int, int)

int main() {

    abs_mock.setMockValue(0);
    int x = -10;
    std::cout << "normal abs: " << abs(x) << std::endl;
    abs_mock.enable();
    std::cout << "mock abs: " << abs(x) << std::endl;
    abs_mock.disable();
    std::cout << "normal abs: " << abs(x) << std::endl;
    abs_mock.enable();
    std::cout << "mock abs: " << abs(x) << std::endl;
    abs_mock.disable();
    std::cout << "normal abs: " << abs(x) << std::endl;
    return 0;
}