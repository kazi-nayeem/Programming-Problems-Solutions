#include<stdio.h>

#define MAX 1000005

short int flag[MAX];

void sieve(void);

int main()
{
    sieve();
    int n, a;
    int f;
    while(scanf("%d", &n) == 1 && (n != 0))
    {
        f = 0;
        printf("%d:\n", n);
        if(n&1)
        {
            if(!flag[n-2])
            {
                printf("%d+%d\n", 2, n - 2);
                f = 1;
            }
        }
        else
        {
            for(a = 2; a < n; a++)
                if((!flag[a]) && (!flag[n-a]))
                {
                    f = 1;
                    printf("%d+%d\n", a, n - a);
                    break;
                }
        }
        if(f == 0)
            printf("NO WAY!\n");
    }
    return 0;
}

void sieve(void)
{
    flag[0] = 1, flag[1] = 1;
    long int i, j, k;
    for(i = 4; i <= MAX; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAX ; i += 2)
    {
        if(!flag[i])
        {
            k = MAX / i;
            for(j = i; j <= k ; j += 2)
                flag[i * j] = 1;
        }
    }
    return;
}
