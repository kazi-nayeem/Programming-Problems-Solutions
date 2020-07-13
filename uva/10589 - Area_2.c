#include<stdio.h>
#include<math.h>

int main()
{
    int n, m;
    int a, i;
    int flag;
    int sa;
    double x, y;
    while(scanf("%d %d", &n, &a) == 2)
    {
        if(n == 0 && a == 0) break;
        m = 0;
        sa = a * a;
        for(i = 0; i < n; i++)
        {
            scanf("%lf %lf", &x, &y);
            flag = 1;
            if(x * x + y * y > sa) flag = 0;
            if((x - a) * (x - a) + y * y > sa) flag = 0;
            if((x - a) * (x - a) + ( y -a ) * ( y - a ) > sa) flag = 0;
            if(x * x + (y-a)*(y-a) > sa) flag = 0;
            if(flag) m++;
        }
        printf("%.5lf\n", (double) a * a * m / n);
    }
    return 0;
}
