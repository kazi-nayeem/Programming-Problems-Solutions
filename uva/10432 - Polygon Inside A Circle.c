#include<stdio.h>
#include<math.h>
#include<stdlib.h>

const double pi = acos(-1);

int main()
{
    double n, r, area;
    while(scanf("%lf%lf", &r, &n) == 2)
    {
        area = r*r*n*sin(2*pi/n)/2;
        printf("%.3lf\n", area);
    }
    return 0;
}
