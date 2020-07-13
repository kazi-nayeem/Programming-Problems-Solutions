#include<stdio.h>

int main()
{
    unsigned long long int n, sum;
    int i;
    while(scanf("%llu", &n) == 1)
    {
        for(i = 1, sum = 1; sum <= n; ++i)
            sum += i;
        printf("%d\n", --i);
    }
    return 0;
}
