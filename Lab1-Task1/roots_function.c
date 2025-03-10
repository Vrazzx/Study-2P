#include <math.h>
#include <stdio.h>

void find_roots(double a, double b, double c, double roots[2], int *root_count,
                double epsilon) {
  // Если а ноль или меньше эпсилон корней нет
  if (a == 0 || a < epsilon) {
    *root_count = 0;
    return;
  }
  // Если абс значение б или с меньше эпсилон зануляем
  if (fabs(b) < epsilon) {
    b = 0;
  }
  if (fabs(c) < epsilon) {
    c = 0;
  }
  // Дискрименант
  double discrimenant = (b * b) - 4 * a * c;
  if (sqrt(discrimenant) < epsilon) {
    discrimenant = 0;
  }

  if (discrimenant > 0) {
    // Применяем формулу Виетта если а = 1
    if (a == 1) {
      if (b > 0) {
        roots[0] = (-b - sqrt(discrimenant)) / (2 * a);
        roots[1] = c / (a * roots[0]);
      } else {
        roots[1] = (-b + sqrt(discrimenant)) / (2 * a);
        roots[0] = c / (a * roots[1]);
      }
      // Иначе обычная формула
    } else {
      roots[0] = (-b + sqrt(discrimenant)) / 2 * a;
      roots[1] = (-b - sqrt(discrimenant)) / 2 * a;
    }

    *root_count = 2;
    // Сортируем корни
    if (roots[0] > roots[1]) {
      double temp = roots[0];
      roots[0] = roots[1];
      roots[1] = temp;
    }
    // Случай дискрименанта = 0
  } else if (discrimenant == 0) {
    roots[0] = -b / (2 * a);
    *root_count = 1;
  } else {
    *root_count = 0;
  }
}