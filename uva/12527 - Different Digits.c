#include<stdio.h>

#define MAX 5001
int flag[MAX];

void different(void);

int main()
{
    different();
    int n, m;
    int total;
    while(scanf("%d %d", &m, &n) == 2)
    {
        total = 0;
        if(m > n)
            m ^= n ^= m ^= n;
        for(; m <= n; m++)
            if(flag[m] == 0)
                total++;
        printf("%d\n", total);
    }
    return 0;
}

void different(void)
{
    int number[10];
    int i, j;
    int m;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < 10; j++)
            number[j] = 0;
        for(j = i; j > 0; j /= 10)
        {
            m = j % 10;
            if(number[m] == 0)
                number[m] = 1;
            else
            {
                flag[i] = 1;
                break;
            }
        }
    }
    return;
}
