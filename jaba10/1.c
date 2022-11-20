#include <stdio.h>
#include <math.h>
#include <locale.h>
#define e 2.7
double fa(double x)
{
    double y;
    if (x <= 3)
    {
        y = pow(x, 2) - 3 * x + 9;
    }
    else
    {
        1 / (pow(x, 3) + 3);
    }
    return y;
}
double fb(double x)
{
    double y;
    y = x * pow(e, sin(pow(x, 2)));
    return y;
}
int zadanie1(int x)
{
    printf("fa(x)=%lf , fb(x)=%lf \n", fa(x), fb(x));
    printf("Произведение: %lf \nРазность квадратов: %lf \nУдвоенная сумма: %lf\n", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
}
long long int factorial(int count)
{
    long long int vlfct = 1;
    for (int i = 1; i <= count; i++)
        vlfct = vlfct * i;
    return vlfct;
}
double sin_n(double x, int N)
{
    double sum = 0;
    for (int k = 1; k <= N; k++) // цикл для переменной i от 1 до k с шагом 1
    {
        sum = sum + pow(-1.0, k - 1) * pow(x, 2 * k - 1) / factorial((2 * k - 1)); // добавляем значение i к сумме
    }
    return sum;
}


double sin_eps(double x, double eps)
{
    double n = x, sum = 0;
    int i = 1;
    do {
        sum += n;
        n *= -1.0 * pow(x, 2) / ((2 * i) * (2 * i + 1));
        i++;
    } while (fabs(n) > eps);

    return sum;
}

int zadanie2(double x, int N, double eps)
{

    double result1 = sin(x);
    printf("sin(x): %lf\n", result1);
    double result2 = sin_n(x, N);
    printf("sin(x): %lf\n", result2);
    double result3 = sin_eps(x, eps);
    printf("ряд Макларена: %lf", result3);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    double x = 3.0;
    int N = 15;
    double eps = 0.0001;
    zadanie1(x);
    zadanie2(x, N, eps);
    return 0;
}