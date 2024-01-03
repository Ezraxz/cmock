#include <dlfcn.h>

#define MOCK_TEST_P0(func_name, ret)                                                             \
  typedef ret (*func_name##_func_t)();                                                          \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)()>(dlsym(RTLD_NEXT, #func_name)); \
  MockFunction<ret()> func_name##_mock(func_name##_func);                                          \
  extern "C" ret func_name() {                                                                  \
    return func_name##_mock();                                                                     \
  }

#define MOCK_TEST_P1(func_name, ret, t1)                                                             \
  typedef ret (*func_name##_func_t)(t1 p1);                                                          \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1)>(dlsym(RTLD_NEXT, #func_name)); \
  MockFunction<ret(t1)> func_name##_mock(func_name##_func);                                          \
  extern "C" ret func_name(t1 p1) {                                                                  \
    return func_name##_mock(p1);                                                                     \
  }

#define MOCK_TEST_P2(func_name, ret, t1, t2)                                                             \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2);                                                       \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2)>(dlsym(RTLD_NEXT, #func_name)); \
  MockFunction<ret(t1, t2)> func_name##_mock(func_name##_func);                                          \
  extern "C" ret func_name(t1 p1, t2 p2) {                                                               \
    return func_name##_mock(p1, p2);                                                                     \
  }

#define MOCK_TEST_P3(func_name, ret, t1, t2, t3)                                                             \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3);                                                    \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2, t3)>(dlsym(RTLD_NEXT, #func_name)); \
  MockFunction<ret(t1, t2, t3)> func_name##_mock(func_name##_func);                                          \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3) {                                                            \
    return func_name##_mock(p1, p2, p3);                                                                     \
  }

#define MOCK_TEST_P4(func_name, ret, t1, t2, t3, t4)                                                             \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3, t4 p4);                                                 \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2, t3, t4)>(dlsym(RTLD_NEXT, #func_name)); \
  MockFunction<ret(t1, t2, t3, t4)> func_name##_mock(func_name##_func);                                          \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3, t4 p4) {                                                         \
    return func_name##_mock(p1, p2, p3, p4);                                                                     \
  }

#define MOCK_TEST_P5(func_name, ret, t1, t2, t3, t4, t5)                                                             \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5);                                              \
  func_name##_func_t func_name##_func = reinterpret_cast<ret (*)(t1, t2, t3, t4, t5)>(dlsym(RTLD_NEXT, #func_name)); \
  MockFunction<ret(t1, t2, t3, t4, t5)> func_name##_mock(func_name##_func);                                          \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) {                                                      \
      return func_name##_mock(p1, p2, p3, p4, p5);                                                                   \
  }

#define MOCK_TEST_P6(func_name, ret, t1, t2, t3, t4, t5, t6)                           \
  typedef ret (*func_name##_func_t)(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6);         \
  func_name##_func_t func_name##_func =                                                \
      reinterpret_cast<ret (*)(t1, t2, t3, t4, t5, t6)>(dlsym(RTLD_NEXT, #func_name)); \
  MockFunction<ret(t1, t2, t3, t4, t5, t6)> func_name##_mock(func_name##_func);        \
  extern "C" ret func_name(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6) {                 \
      return func_name##_mock(p1, p2, p3, p4, p5, p6);                                 \
  }
