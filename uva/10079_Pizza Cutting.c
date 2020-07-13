#include<stdio.h>

int main()
{
    long long int n, total, i;
    while(scanf(" %lld", &n) == 1)
    {
        if(n<0) break;
        for(total = 1, i = 0; i <= n ; ++i)
                total += i;
            printf("%lld\n", total);
    }
    return 0;
}
