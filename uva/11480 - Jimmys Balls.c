#include<stdio.h>

int main()
{
    int n, total;
    int i, j, k;
    while(scanf("%d", &n) == 1)
    {
        for(total = 0, i = 1; i < (n/3); i++)
        {
            k = n - i;
            for(j = i + 1; j < k - j; j++)
            {
                total ++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
