#include "integral_function.h"
#include <assert.h>
double Function(double x) { return cos(x); }
void integral_test1() {
  double a = 0;  // нижний предел Интеграла
  double b = 20; // верхний предел интеграла
  int n = 20000000; // Количество разбиений на отрезке [a,b]

  double result = calculation(a, b, n, Function);
  double expect = 0.9129452507;
  double pogreh = 1e-6;
  assert(fabs(result - expect) <= pogreh);
}
void integral_test2() {
  double a = 8;
  double b = 30;
  int n = 1000000;
  double result = calculation(a, b, n, Function);
  double expect = -1.977390;
  assert(fabs(result - expect) <= 1e-6);
}
void integral_test3() {
  double a = 14;
  double b = 90;
  int n = 100000000;
  double result = calculation(a, b, n, Function);
  double expect = -0.096611;
  assert(fabs(result - expect) <= 1e-6);
}
void integral_test4() {
  double a = 3;
  double b = 6;
  int n = 100000;
  double result = calculation(a, b, n, Function);
  double expect = -0.420536;
  assert(fabs(result - expect) <= 1e-6);
}
int main() {
  integral_test1();
  integral_test2();
  integral_test3();
  integral_test4();
  return 0;
}
