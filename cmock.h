#include <dlfcn.h>
#include <functional>

#include "mock_define.h"

template<typename T>
class MockFunction;

template<typename Ret, typename... Args>
class MockFunction<Ret(Args...)> {
public:
  MockFunction(Ret (*func_ptr)(Args...))
  : real_func_(func_ptr) {}

  void setMockValue(Ret ret_val) {
    mock_value_ = ret_val;
  }

  Ret operator()(Args... args) {
    if (times_ >= 0) {
      if (times == 0) {
        is_mock_ = false;
      }
      times_ -= 1;
    }
    return is_mock_ ? mock_value_ : real_func_(args...);
  }

  void enable() { is_mock_ = true; } 
  void disable() { is_mock_ = false; }
  void enableMultipleTimes(int times) {
    times_ = times;
    is_mock_ = true;
  }

private:
  bool is_mock_ = false;
  Ret (*real_func_)(Args...);
  Ret mock_value_;
  int times_ = -1;
};
