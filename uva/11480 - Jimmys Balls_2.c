#include<stdio.h>

int main()
{
    long int n;
    register long int i, j, k, total, test = 1;
    while(scanf("%ld", &n) == 1 && n != 0)
    {
        k = n / 3;
        for(total = 0, i = 1; i < k; i++)
        {
            j = n - (i * 3) - 1;
            total += j/2;
        }
        printf("Case %d: %ld\n", test++, total);
    }
    return 0;
}
