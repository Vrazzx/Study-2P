#include "my_math_lib.h"
#include <math.h>
#include <stdio.h>

int main() {
  int choice;
  printf("Введите 1 для квадратного уровнения и 2 для интеграла: \n");
  scanf("%d", &choice);
  if (choice == 1) {
    double a, b, c;
    printf("Введите коэфиценты квадратного уравнения:\n");
    scanf("%lf", &a);
    if (a == 0) {
      return 1;
    }
    scanf("%lf", &b);
    scanf("%lf", &c);
    double d = discriminant(a, b, c);
    countRoots(d, a, b);
    printRoots(d, a, b);
  }
  if (choice == 2) {
    double a, b;
    int n;
    printf("Введите отрезок [a, b]\n");
    printf("Введите a: ");
    scanf("%lf", &a);
    printf("Введите b: ");
    scanf("%lf", &b);
    printf("Введите количество разбиений: ");
    scanf("%d", &n);
    double intg = integral(a, b, n);
    printf("Значение интеграла приблизительно равно: %lf\n", intg);
  }

  return 0;
}
