#include "my_math_lib.h"
#include <stdio.h>

int main() {
  int choice;
  printf("Введите 1 для квадратного уравнения, 2 для интеграла, 3 для "
         "односвязного списка: \n");
  scanf("%d", &choice);

  switch (choice) {
  case 1: {
    double a, b, c;
    printf("Введите коэффициенты квадратного уравнения:\n");
    scanf("%lf", &a);
    if (a == 0) {
      printf("Коэффициент 'a' не может быть равен 0.\n");
      return 1;
    }
    scanf("%lf", &b);
    scanf("%lf", &c);
    double d = discriminant(a, b, c);
    countRoots(d, a, b);
    printRoots(d, a, b);
    break;
  }

  case 2: {
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
    break;
  }

  case 3: {
    int n;
    printf("Введите количество элементов: ");
    scanf("%d", &n);

    struct Node *head = createNodeList(n);

    printf("Список:\n");
    printNodeList(head);

    freeMemory(head);
    break;
  }

  default:
    printf("Неверный выбор. Пожалуйста, введите 1, 2 или 3.\n");
    break;
  }

  return 0;
}
