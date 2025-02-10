#include <stdio.h>
#include <math.h>
double func(double x)
{
    return sin(x);
}
double integral(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0;
    for(int i = 1; i<n; i++)
    {
        sum += func(a+i*h);
    }
    double intg = (h/2)*(func(a) + 2*sum + func(b));
    return intg;
}
int main()
{
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
    return 0;

}
