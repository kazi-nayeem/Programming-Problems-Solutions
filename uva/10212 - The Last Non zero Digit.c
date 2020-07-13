#include<stdio.h>

int main()
{
    long long int n, m;
    long long int i, c;
    long long int total;
    while(scanf("%lld %lld", &n, &m) == 2)
    {
        total = 1;
        c = n-m+1;
        for(i = n; i >= c; i--)
        {
            total *= i;
            while(total%10 == 0)
                total /= 10;
            total %= 100000000;
        }
        printf("%lld\n", total % 10);
    }
    return 0;
}
