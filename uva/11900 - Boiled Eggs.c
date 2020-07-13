#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int time, test;
    int n, p, q, i;
    int egg[30], total;
    int max_egg;
    scanf(" %d", &time);
    for(test = 0; test < time;)
    {
        scanf(" %d %d %d", &n, &p, &q);
        for(i = 0; i < n; ++i)
            scanf(" %d", &egg[i]);
        qsort(egg, n, sizeof(int), comp);
        for(total = max_egg = i = 0; i < n; ++i)
        {
            total += egg[i];
            if(total <= q)
                max_egg++;
            else
                break;
        }
        if(max_egg > p)
            max_egg = p;
        printf("Case %d: %d\n", ++test, max_egg);
    }
    return 0;
}
