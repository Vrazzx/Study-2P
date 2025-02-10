#include <stdio.h>
#include <math.h>

double discriminant(double a, double b, double c)
{
    double d = ((b * b) - (4*a*c));
    return d;
}
void printRoots(double d, double a, double b)
{
    if (d > 0)
    {
        double x1 = (-b + sqrt(d))/(2*a);
        double x2 = (-b - sqrt(d))/(2*a);
        printf("Корни 1 и 2 равны соответсвенно: %lf, %lf\n", x1, x2);
    }
    else if (d == 0)
    {
        double x = (-b)/(2*a);
        printf("Корень равен: %lf\n", x);
    }
    else
    {
        printf("Нет действительных корней.\n");
    }
}
void countRoots(double d, double a, double b)
{
    if (d > 0)
    {
        printf("Корней 2 \n");
    }
    else if (d == 0)
    {
        double x = (-b)/(2*a);
        printf("Корень 1\n");
    }
    else
    {
        printf("Нет действительных корней.\n");
    }

}
int main()
{
    double a, b, c;
    printf("Введите коэфиценты квадратного уравнения:\n");
    scanf("%lf", &a);
    if(a == 0)
    {
        return 1;
    }
    scanf("%lf", &b);
    scanf("%lf", &c);
    double d = discriminant(a, b, c);
    countRoots(d, a, b);
    printRoots(d, a, b);
    return 0;
}