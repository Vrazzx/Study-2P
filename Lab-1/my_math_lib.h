#include <math.h>
#include <stdlib.h>
double discriminant(double a, double b, double c);
void printRoots(double d, double a, double b);
void countRoots(double d, double a, double b);
double func(double x);
double integral(double a, double b, int n);
struct Node;
struct Node *createNodeList(int n);
void printNodeList(struct Node *head);
void freeMemory(struct Node *head);
