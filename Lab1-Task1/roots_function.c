#include <math.h>
#include <stdio.h>

void find_roots(double a, double b, double c, double roots[2], int *root_count,
                double epsilon) {
  if (a == 0) {
    *root_count = 0;
    return;
  }
  double discrimenant = (b * b) - 4 * a * c;
  if (sqrt(discrimenant) < epsilon) {
    discrimenant = 0;
  }
  if (discrimenant > 0) {
    if(a == 1){
      if (b > 0) {
        roots[0] = (-b - sqrt(discrimenant)) / (2 * a);
        roots[1] = c / (a * roots[0]);
      } else {
        roots[1] = (-b + sqrt(discrimenant)) / (2 * a);
        roots[0] = c / (a * roots[1]);
      }
    } else{
      roots[0] = (-b + sqrt(discrimenant)) / 2 * a;
      roots[1] = (-b - sqrt(discrimenant)) / 2 * a;
    }
    
    *root_count = 2;

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
