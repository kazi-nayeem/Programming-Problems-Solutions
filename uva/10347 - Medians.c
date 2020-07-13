#include<stdio.h>
#include<math.h>

int main()
{
    double area, s;
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
    {
        if(a+b > c && c + a > b && b + c > a)
        {
            s = (a+b+c) / 2;
            area = sqrt(s * (s - a)* (s - b) * (s - c));
            area = area * 4 / 3;
            printf("%.3lf\n", area);
        }
        else
            printf("-1.000\n");
    }
    return 0;
}
