#include <math.h>
#include <stdio.h>

void find_roots(double a, double b, double c, double roots[2],
                int *root_count) {
  if (a == 0) {
    *root_count = 0;
    return;
  }
  double discrimenant = (b * b) - 4 * a * c;
  if (discrimenant > 0) {
    *root_count = 2;
    if (b < -1E-6 && a == 1) {
      roots[0] = (-b + sqrt(discrimenant)) / 2 * a;
      roots[1] = c / (a * roots[0]);
    } else {
      roots[0] = (-b + sqrt(discrimenant)) / 2 * a;
      roots[1] = (-b - sqrt(discrimenant)) / 2 * a;
    }

    if (roots[0] > roots[1]) {
      double temp = roots[0];
      roots[0] = roots[1];
      roots[1] = temp;
    }
  } else if (discrimenant == 0) {
    roots[0] = -b / (2 * a);
    *root_count = 1;
  } else {
    *root_count = 0;
  }
}
