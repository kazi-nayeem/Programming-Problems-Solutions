#include<stdio.h>

int main()
{
    long long int n;
    while(scanf(" %lld", &n) == 1)
    {
        if(n < 0) break;
        n = n * (n + 1);
        n /= 2;
        printf("%lld\n", n + 1);
    }
    return 0;
}
