#include<stdio.h>

#define MAX 12

int main()
{
    int t, num[MAX], f = 0;
    register i, j, k, l,m, n;
    while(scanf("%d", &t) == 1)
    {
        if(t == 0) break;
        if(f) putchar('\n');
        f = 1;
        for(i = 0; i < t; i++)
            scanf("%d", &num[i]);
        for(i = 0; i < t - 5; i++)
            for(j = i + 1; j < t - 4; j++)
            for(k = j + 1; k < t - 3; k++)
            for(l = k + 1; k < t - 2; l++)
            for(m = l + 1; m < t - 1; m++)
            for(n = m + 1; n < t; n++)
            printf("%d %d %d %d %d %d\n", num[i], num[j], num[k], num[l], num[m],  num[n]);
    }
    return 0;
}
