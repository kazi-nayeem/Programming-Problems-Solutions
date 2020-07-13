#include<stdio.h>

#define MAX 32768
#define MAXP 3513

short int flag[MAX];
int prime[MAXP];

void sieve(void);

int main()
{
    sieve();
    int n, gold;
    int i, j;
    while(scanf("%d", &n) == 1 && (n != 0))
    {
        gold = 0;
        j = n / 2;
        for(i = 0; prime[i] <= j; i++)
            if(!flag[n - prime[i]])
                gold++;
        printf("%d\n", gold);
    }
    return 0;
}

void sieve(void)
{
    flag[0] = 1, flag[1] = 1;
    int i, j, k = 1, add;
    for(i = 4; i <= MAX; i += 2)
        flag[i] = 1;
    for(i = 3; i < MAX ; i += 2)
    {
        if(!flag[i])
        {
            prime[k++] = i;
            if(MAX/i >= i)
            {
                add = i * 2;
            for(j = i * i; j < MAX ; j += add)
                flag[j] = 1;
            }
        }
    }
    prime[0] = 2;
    return;
}

