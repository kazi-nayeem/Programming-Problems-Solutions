#include<stdio.h>
#include<stdlib.h>

typedef struct st{long long int n;
                    int divisor;
} man;

int comp(const void *a, const void *b)
{
    man i, j;
    i = *(man *) a;
    j = *(man *) b;
    if(i.divisor == j.divisor)
    {
        return (int)j.n - i.n;
    }
    return (int)i.divisor - j.divisor;
}
void in(man black[]);

int main()
{
    man black[1001];
    in(black);
    long long int i, n, j = 1;
    qsort(black, 1001, sizeof(man), comp);
    scanf("%lld", &i);
    while(i--)
    {
        scanf("%lld", &n);
        printf("Case %lld: %lld\n", j++, black[n].n);
    }
    return 0;
}

void in(man black[])
{
    int i, j;
    for(i = 1; i < 1001; i++)
    {
        black[i].n = i;
        black[i].divisor = 1;
    }
    black[0].n = 0;
    black[0].divisor = 0;
    for(i = 2; i < 1001; i++)
    {
        for(j = i; j < 1001; j += i)
            black[j].divisor++;
    }
    return;
}
