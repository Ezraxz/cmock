#include <iostream>
#include <cmath>
#include "cmock.h"

/* 进阶用法——设置mock次数：可以不用手动关闭；并且如果一个函数中包含多次mock函数调用，可以设置前几次返回mock值，后面的不返回mock值
 1. 定义Mock函数
 2. 设置返回值
 3. 开启并设置mock次数-调用
*/ 

// 1. 定义Mock函数
MOCK_TEST_P1(abs, int, int)

int main() {
    // 2.设置返回值
    abs_mock.setMockValue(0);
    // 3.开启并设置mock次数-调用
    abs_mock.enableLimitedTimes(3);
    int x = -10;
    std::cout << "mock abs: " << abs(x) << std::endl;
    std::cout << "mock abs: " << abs(x) << std::endl;
    std::cout << "mock abs: " << abs(x) << std::endl;
    std::cout << "normal abs: " << abs(x) << std::endl;
    return 0;
}