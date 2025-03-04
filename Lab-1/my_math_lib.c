#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double discriminant(double a, double b, double c) {
  double d = ((b * b) - (4 * a * c));
  return d;
}
void printRoots(double d, double a, double b) {
  if (d > 0) {
    double x1 = (-b + sqrt(d)) / (2 * a);
    double x2 = (-b - sqrt(d)) / (2 * a);
    printf("Корни 1 и 2 равны соответсвенно: %lf, %lf\n", x1, x2);
  } else if (d == 0) {
    double x = (-b) / (2 * a);
    printf("Корень равен: %lf\n", x);
  } else {
    printf("Нет действительных корней.\n");
  }
}
void countRoots(double d, double a, double b) {
  if (d > 0) {
    printf("Корней 2 \n");
  } else if (d == 0) {
    double x = (-b) / (2 * a);
    printf("Корень 1\n");
  } else {
    printf("Нет действительных корней.\n");
  }
}

double func(double x) { return x * x; }

double integral(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0;
  for (int i = 1; i < n; i++) {
    sum += func(a + i * h);
  }
  double intg = (h / 2) * (func(a) + 2 * sum + func(b));
  return intg;
}

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNodeList(int n) {
  if (n == 0) {
    return NULL;
  }

  struct Node *nNode = (struct Node *)malloc(sizeof(struct Node));
  int a;
  printf("Введите значение узла: \n");
  scanf("%d", &a);
  nNode->data = a;
  nNode->next = createNodeList(n - 1);
  return nNode;
}

void printNodeList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
void freeMemory(struct Node *head) {
  struct Node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
