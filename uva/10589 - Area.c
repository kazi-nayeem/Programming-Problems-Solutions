#include<stdio.h>
#include<math.h>

int main()
{
    long int n, a;
    register double ax, ay;
    register int i, j;
    double x, y;
    double root;
    long int total;
    while(scanf("%ld %ld", &n, &a) == 2)
    {
        if(n == 0) break;
        total = 0;
        for(i= 0; i < n; i++)
        {
            scanf("%lf %lf", &x, &y);
            if(sqrt(x*x+y*y) <= a)
            {
                ax = (double) a - x;
                ay = (double) a - x;
                if(sqrt(ax*ax + y*y) <= a)
                {
                    if(sqrt(x*x+ay*ay) <= a)
                    {
                        if(sqrt(ax*ax+ay*ay) <= a)
                            total++;
                    }
                }
            }
        }
        printf("%.5lf\n", (double) total * a * a / n);
    }
    return 0;
}
