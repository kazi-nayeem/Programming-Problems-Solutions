#include<stdio.h>
#include<math.h>

int main()
{
    double l, w, h, a, total, pi, k;
    pi = acos(-1);
    while(scanf("%lf %lf %lf %lf", &l, &w, &h, &a) == 4)
    {
        k = l * tan(a*pi/180);
        if(k > h)
            total = 0.5 * w * h * h * tan((90-a)*pi/180);
        else
            total = l*w*(h-k/2);
        printf("%.3lf mL\n", total);
    }
    return 0;
}
