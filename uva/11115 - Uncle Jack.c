#include<stdio.h>

int main()
{
    int n, r, i;
    unsigned long long int total;
    while(scanf("%d %d", &r, &n) == 2)
    {
        if(n == 0 && r == 0) break;
        total = 1;
        for(i = n - r; n > i; n--)
            total *= n;
        printf("%llu\n", total);
    }
    return 0;
}
