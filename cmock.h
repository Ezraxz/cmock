#include <dlfcn.h>

#define MOCK_TEST_P1(func_name, ret, t1, expect)                                                     \
  typedef ret (*func_name##_func_t)(t1 p1);                                                          \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1)>(dlsym(RTLD_NEXT, #func_name)); \
  bool func_name##_mock = false;                                                                     \
  extern "C" ret func_name(t1 p1) {                                                                  \
    if (func_name##_mock) {                                                                          \
      return expect;                                                                                 \
    } else {                                                                                         \
      return func_name##_func(p1);                                                                   \
    }                                                                                                \
  }

#define MOCK_TEST_P2(func_name, ret, t1, t2, expect)                                                     \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2);                                                       \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2)>(dlsym(RTLD_NEXT, #func_name)); \
  bool func_name##_mock = false;                                                                         \
  extern "C" ret func_name(t1 p1, t2 p2) {                                                               \
    if (func_name##_mock) {                                                                              \
      return expect;                                                                                     \
    } else {                                                                                             \
      return func_name##_func(p1, p2);                                                                   \
    }                                                                                                    \
  }

#define MOCK_TEST_P3(func_name, ret, t1, t2, t3, expect)                                                     \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3);                                                    \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2, t3)>(dlsym(RTLD_NEXT, #func_name)); \
  bool func_name##_mock = false;                                                                             \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3) {                                                            \
    if (func_name##_mock) {                                                                                  \
      return expect;                                                                                         \
    } else {                                                                                                 \
      return func_name##_func(p1, p2, p3);                                                                   \
    }                                                                                                        \
  }

#define MOCK_TEST_P4(func_name, ret, t1, t2, t3, t4, expect)                                                     \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3, t4 p4);                                                 \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2, t3, t4)>(dlsym(RTLD_NEXT, #func_name)); \
  bool func_name##_mock = false;                                                                                 \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3, t4 p4) {                                                         \
    if (func_name##_mock) {                                                                                      \
      return expect;                                                                                             \
    } else {                                                                                                     \
      return func_name##_func(p1, p2, p3, p4);                                                                   \
    }                                                                                                            \
  }

#define MOCK_TEST_P5(func_name, ret, t1, t2, t3, t4, t5, expect)                                                     \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5);                                              \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2, t3, t4, t5)>(dlsym(RTLD_NEXT, #func_name)); \
  bool func_name##_mock = false;                                                                                     \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) {                                                      \
    if (func_name##_mock) {                                                                                          \
      return expect;                                                                                                 \
    } else {                                                                                                         \
      return func_name##_func(p1, p2, p3, p4, p5);                                                                   \
    }                                                                                                                \
  }

#define MOCK_TEST_P6(func_name, ret, t1, t2, t3, t4, t5, t6, expect)                   \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6);         \
  func_name##_func_t func_name##_func =                                                \
      reinterpret_cast<ret (*)(t1, t2, t3, t4, t5, t6)>(dlsym(RTLD_NEXT, #func_name)); \
  bool func_name##_mock = false;                                                       \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6) {                 \
    if (func_name##_mock) {                                                            \
      return expect;                                                                   \
    } else {                                                                           \
      return func_name##_func(p1, p2, p3, p4, p5, p6);                                 \
    }                                                                                  \
  }
