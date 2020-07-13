#include<stdio.h>

int main()
{
    unsigned long long int total;
    int n, r;
    int i;
    while(scanf("%d%d", &n, &r) == 2)
    {
        if(n == 0 && r == 0) break;
        if(r > n / 2)
            r  = n - r;
        for(total = i = 1; i <= r; i++, n--)
            total = total * n / i;
        printf("%lld\n", total);
    }
    return 0;
}
