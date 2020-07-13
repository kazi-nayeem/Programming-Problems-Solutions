#include<stdio.h>

#define MAX 1000001
int sum[MAX];

void sumoffact(void);
void sieve(void);

int main()
{
    sumoffact();
    printf("ok");
    return 0;
    int n;
    while(scanf("%d", &n) == 1)
        printf("%d\n", sum[n]);
    return 0;
}

void sumoffact(void)
{
    sieve();
    return;
}

void sieve(void)
{
    int i, j, k = 1;
    int add;
    sum[2] = 1;
    for(i=4; i<MAX;i+= 2)
        sum[i] = 1;
    for(i = 3; i<MAX;i++)
    {
        if(sum[i] == 0)
        {
            primenumber[k++] = i;
            if(MAX/i >= i)
            {
                add = i + i;
                for(j = i * i; j < MAX; j+= add)
                    flag[j] = 1;
            }
        }
    }
    return;
}
