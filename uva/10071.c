#include<stdio.h>

int main()
{
    int v, t;
    long long int s;
    while(scanf("%d %d", &v, &t)==2)
    {
        if(v >= 0)
            s = 2 * v * t;
        else
            s = -(2 * v * t);
        printf("%lld\n", s);
    }
    return 0;
}
