#include<stdio.h>
#include<string.h>

int main()
{
    long int i, j, k;
    char senten[1000];
    int test = 1, t;
    while(scanf(" %s", senten) == 1)
    {
        scanf("%d", &t);
        printf("Case %d:\n", test++);
        for(;t > 0; --t)
        {
            scanf("%ld %ld", &i , &j);
            if(i > j)
                i ^= j ^= i ^= j;
                k = i;
            for(i = i + 1; i <= j; ++i)
            {
                if(senten[k] != senten[i])
                            break;
            }
            if(i - 1 == j)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
