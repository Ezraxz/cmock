#include <dlfcn.h>
#include <functional>
#include <vector>
#include <algorithm>

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

  void setMockMultipleValue(std::vector<Ret> ret_val) {
    std::reverse(ret_val.begin(), ret_val.end());
    mock_value_array_ = ret_val;
  }

  Ret operator()(Args... args) {
    if (wait_times_ > 0) {
      wait_times_ -=1;
      return real_func_(args...);
    }
    if (is_mock_ && !mock_value_array_.empty()) {
      mock_value_ = mock_value_array_.back();
      mock_value_array_.pop_back();
    }
    if (times_ >= 0) {
      if (times_ == 0) {
        is_mock_ = false;
      }
      times_ -= 1;
    }
    return is_mock_ ? mock_value_ : real_func_(args...);
  }

  void enable() { is_mock_ = true; } 

  void enableLimitedTimes(uint32_t times) {
    times_ = times;
    is_mock_ = true;
  }

  void enableWaitTimes(uint32_t wait_times) {
    wait_times_ = wait_times;
    is_mock_ = true;
  }

  void disable() { is_mock_ = false; }

private:
  bool is_mock_ = false;
  Ret (*real_func_)(Args...);
  Ret mock_value_;
  std::vector<Ret> mock_value_array_;
  uint32_t times_ = -1;
  uint32_t wait_times_ = 0;
};
