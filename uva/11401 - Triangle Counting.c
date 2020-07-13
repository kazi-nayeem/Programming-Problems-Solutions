#include<stdio.h>

int main()
{
    long long int n, total;
    int i, j;
    while(scanf("%lld", &n) == 1)
    {
        if(n < 3) break;
        total = 0;
        for(i = 1; i < n; i++)
            for(j = i + 1; j < n; j++)
            {
                if(i + j < n)
                    total = total + i - 1;
                else if(i + j > n)
                    total = total + n - j;
            }
        printf("%lld\n", total);
    }
    return 0;
}
