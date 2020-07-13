#include<stdio.h>
#include<stdlib.h>

#define MX 101

int comp1(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int comp2(const void *a, const void *b)
{
    return *(int *) b - *(int *) a;
}

int main()
{
    int morning[MX], evening[MX];
    int n, d, r, i, sum;

    while(scanf("%d %d %d", &n, &d, &r) == 3)
    {
        if(n == 0 && d == 0 && r == 0) return 0;

        for(i = 0; i < n; i++)
            scanf("%d", &morning[i]);
        for(i=0;i<n;i++)
            scanf("%d", &evening[i]);

        qsort(morning, n, sizeof (int), comp1);
        qsort(evening, n, sizeof (int), comp2);

        sum = 0;
        for(i = 0; i < n; i++)
        {
            if(d<morning[i]+evening[i])
                sum += morning[i]+evening[i] - d;
        }
        printf("%d\n", sum*r);
    }
    return 0;
}
