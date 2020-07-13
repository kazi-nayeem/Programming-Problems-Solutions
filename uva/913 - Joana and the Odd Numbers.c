#include<stdio.h>

int main()
{
    long long int n;
    while(scanf(" %lld", &n) == 1)
    {
        n = (n/2) + 1;
        n = (6 * n * n) - 9;
        printf("%lld\n", n);
    }
    return 0;
}
