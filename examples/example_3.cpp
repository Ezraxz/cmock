#include <iostream>
#include <cmath>
#include "cmock.h"

/* 进阶用法——设置不同的返回值，如果调用次数大于设定的返回值个数，最后的调用将返回设置列表里的最后一个值。
 1. 定义Mock函数
 2. 设置返回值数组
 3. 开启-调用-关闭
*/ 

// 1. 定义Mock函数
MOCK_TEST_P1(abs, int, int)

int main() {
    std::vector<int> mock_ret = {1, 2, 3};
    // 2. 设置返回值数组
    abs_mock.setMockMultipleValue(mock_ret);
    int x = -10;
    // 3. 开启-调用-关闭
    abs_mock.enable();
    std::cout << "mock abs: " << abs(x) << std::endl;
    std::cout << "mock abs: " << abs(x) << std::endl;
    std::cout << "mock abs: " << abs(x) << std::endl;
    std::cout << "mock abs: " << abs(x) << std::endl;
    abs_mock.disable();
    std::cout << "normal abs: " << abs(x) << std::endl;
    return 0;
}