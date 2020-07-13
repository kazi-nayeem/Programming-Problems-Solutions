#include<stdio.h>
#include<math.h>

int main()
{
    double area;
    double a, b, c, s1, s2;
    while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
    {
        if(a+b > c && c + a > b && b + c > a)
        {
            s1 = (a * a * b * b) + (b * b * c *c) + (c * c * a *a);
            s2 = (a*a*a*a) + (b*b*b*b) +(c*c*c*c);
            area = sqrt((2 * s1) - s2);
            area = area / 3 ;
            printf("%.3lf\n", area);
        }
        else
            printf("-1.000\n");
    }
    return 0;
}

