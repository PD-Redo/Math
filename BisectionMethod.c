#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double my_pow(double var, double pwr);
double f(double x, double y);
double df_d(double x);
double a_b(double x, double *l, double *h);
double my_fabs(double abs);
int main()
{
    printf("Say Wallahi");
    int count = 0, n;
    double a = 0, b = 3, c = 0, num;
    printf("Enter number whose root is to be calculated:");
    scanf("%lf", &num);
    printf("Enter the maximum error allowed is 10 to the power of:");
    scanf("%d", &n);
    a_b(num, &a, &b);
    if ((f(a, num) > 0 && f(b, num) < 0) || (f(a, num) < 0 && f(b, num) > 0))
    {
        double values[2];
        c = (a + b) / 2.0;
        do
        {
            count = count + 1;
            values[0] = c;
            if ((my_fabs(f(b, num)) - f(b, num) == my_fabs(f(c, num)) - f(c, num)) ||
                (my_fabs(f(b, num) + f(b, num)) == my_fabs(f(c, num)) + f(c, num)))
            {
                b = c;
                c = (a + b) / 2.0;
                values[1] = c;
                printf("%lf\n", c);
            }
            else if ((my_fabs(f(a, num)) - f(a, num) == my_fabs(f(c, num)) - f(c, num)) ||
                     (my_fabs(f(a, num)) + f(a, num) == my_fabs(f(c, num)) + f(c, num)))
            {
                a = c;
                c = (a + b) / 2.0;
                values[1] = c;
                printf("%lf\n", c);
            }
        } while (my_fabs(values[0] - values[1]) > my_pow(10, n));
        printf("%lf\n", values[1]);
    }
    else
    {
        printf("root:=%lf ", a);
    }
    printf("iterations:%d", count);
    return 0;
}

double f(double x, double y)
{
    double fx = my_pow(x, 2) - y;
    return fx;
}

double df_d(double x)
{
    double df_dx = 2 * x;
    return df_dx;
}

double a_b(double x, double *l, double *h)
{
    double i = 0, a, b;
    bool is_square = false;
    while (!is_square)
    {
        if (my_pow(i, 2) == x)
        {
            *l = i, *h = i + 1;
            is_square = true;
            break;
        }
        else if (my_pow(i, 2) < x && my_pow((i + 1), 2) > x)
        {
            *l = i, *h = i + 1;
            is_square = true;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

double my_pow(double var, double pwr)
{
    double temp = var;
    if (pwr > 0)
    {
        for (int i = 1; i < pwr; i++)
        {
            var *= temp;
        }
    }
    else if (pwr < 0)
    {
        for (int i = 1; i > pwr; i--)
        {
            var /= temp;
        }
    }
    else
    {
        var = 1;
    }
    return var;
}
double my_fabs(double abs)
{

    if (abs < 0)
    {
        abs = -abs;
    }
    else
    {
        abs = abs;
    }
    return abs;
}