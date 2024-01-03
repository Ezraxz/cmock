# CMock

For C/C++ Function Mock.\
Based on Link Seams

## How to use
1. 引入头文件 cmock.h, mock_define.h
2. 参考example

## Todo List
### v1.0
- Base √
- Multiple return one value √
- Multiple return different values
### v2.0
- depend on parameters

## Attention

- 不适用于类成员函数
- 依赖于动态链接，mock函数需要在lib.so中
- 多线程行为不可预测
- 污染全局命名空间
