#include <iostream>
#include <cmath>
#include "cmock.h"

/* 基础用法
 1. 定义Mock函数
 2. 设置返回值
 3. 开启-调用-关闭
*/ 
/*
    支持MOCK_TEST_P0/1/2/3/4/5/6，数字代表需要mock函数的参数个数。
    MOCK_TEST_Px(function_name, return_type, parameter1_type, ...)
*/


// 1. 定义Mock函数
MOCK_TEST_P1(abs, int, int)

int main() {
    // 2.设置返回值
    abs_mock.setMockValue(0);
    int x = -10;
    std::cout << "normal abs: " << abs(x) << std::endl;
    // 3. 开启-调用-关闭
    abs_mock.enable();
    std::cout << "mock abs: " << abs(x) << std::endl;
    abs_mock.disable();
    std::cout << "normal abs: " << abs(x) << std::endl;
    abs_mock.setMockValue(100);
    abs_mock.enable();
    std::cout << "mock abs: " << abs(x) << std::endl;
    abs_mock.disable();
    std::cout << "normal abs: " << abs(x) << std::endl;
    return 0;
}