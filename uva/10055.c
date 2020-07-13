#include<stdio.h>

int main()
{
    long long int m, n;
    while(scanf("%lld %lld", &m, &n)==2)
    {
        if( m < n )
            printf("%lld\n", n - m);
        else
            printf("%lld\n", m - n);
    }
    return 0;
}
