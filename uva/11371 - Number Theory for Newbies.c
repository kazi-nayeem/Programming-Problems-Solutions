#include<stdio.h>

int main()
{
    long long int m, n, temp;
    long long int diff;
    while(scanf("%lld", &m) == 1)
    {
        for(n = 0, temp = m; temp > 0; temp /= 10)
        {
            n *= 10;
            n += (temp % 10);
        }
        diff = n - m;
        if(diff < 0)
            printf("%lld - %lld = %lld = 9 * %lld\n", m, n, -diff, -diff / 9);
        else
            printf("%lld - %lld = %lld = 9 * %lld\n", n, m, diff, diff / 9);
    }
    return 0;
}
