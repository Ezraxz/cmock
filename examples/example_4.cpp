#include <iostream>
#include <cmath>
#include "cmock.h"

/* 进阶用法——等待设定次数的调用后，才开始返回设定好的mock返回值
 1. 定义Mock函数
 2. 设置返回值
 3. 开启并设置等待次数-调用-关闭
*/ 

// 1. 定义Mock函数
MOCK_TEST_P1(abs, int, int)

int main() {
    // 2.设置返回值
    abs_mock.setMockValue(0);
    int x = -10;
    // 3. 开启并设置等待次数-调用-关闭
    abs_mock.enableWaitTimes(2);
    std::cout << "normal abs: " << abs(x) << std::endl;
    std::cout << "normal abs: " << abs(x) << std::endl;
    std::cout << "mock abs: " << abs(x) << std::endl;
    abs_mock.disable();
    std::cout << "normal abs: " << abs(x) << std::endl;
    return 0;
}