#include<stdio.h>

int main()
{
    int n, k;
    long int total;
    int i, j;
    while(scanf("%d %d", &n , &k) == 2 && (n != 0 || k != 0))
    {
        i = n - k + 1;
        for(total = 1, j = 1 ; i <= n; i++, j++)
            total = total * i / j;
        printf("%lld\n", total);
    }
    return 0;
}
