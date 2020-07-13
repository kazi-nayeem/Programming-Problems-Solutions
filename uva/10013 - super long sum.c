#include<stdio.h>

#define MAX 1000002

int main()
{
    long int n, i;
    int sum[MAX], temp1, temp2, flag;
    int t;
    scanf(" %d", &t);
    while(t--)
    {
        scanf(" %d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf(" %d %d", &temp1, &temp2);
            sum[i] = temp1 + temp2;
        }
        for(i = n - 1, flag = 0; i > 0; i--)
        {
            sum[i] += flag;
            flag = 0;
            if(sum[i] > 9)
            {
                sum[i] -= 10;
                flag = 1;
            }
        }
        sum[0] += flag;
        for(i = 0; i < n; i++)
            printf("%d", sum[i]);
        putchar('\n');
        if(t)
            putchar('\n');
    }
    return 0;
}
