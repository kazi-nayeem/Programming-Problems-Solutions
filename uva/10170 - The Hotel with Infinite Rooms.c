#include<stdio.h>
#include<math.h>

int main()
{
    unsigned long long int d, s, n;
    double k;
    while(scanf("%llu %llu", &s, &d) == 2)
    {
        d += s*(s-1)/2;
        k = (double)(-1+sqrt(1+8*d))/2;
        //printf("%lf\n", k);
        printf("%d\n",(int) ceil(k));
    }
    return 0;
}
