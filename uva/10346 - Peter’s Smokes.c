#include<stdio.h>

int main()
{
    int n, k;
    int total, extra, new;
    while(scanf("%d %d", &n, &k) == 2)
    {
        for(total = n; n >= k; n = extra + new)
        {
            extra = n % k;
            new = n / k;
            total += new;
        }
        printf("%d\n", total);
    }
    return 0;
}
