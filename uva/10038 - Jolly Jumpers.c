#include<stdio.h>
#include<stdlib.h>

#define MAX 3001

int comp(const void *a, const void *b)
{
    return(*(int *) a - *(int *) b);
}

int main()
{
    int n;
    int jolly[MAX];
    register int flag, i;
    while(scanf(" %d", &n) == 1)
    {
        scanf(" %d", &jolly[0]);
        for(i = 1; i < n ; ++i)
        {
            scanf(" %d", &jolly[i]);
            jolly[i - 1] = abs(jolly[i] - jolly[i-1]);
        }
        n--;
        qsort(jolly, n, sizeof(int), comp);
        for(flag = 1, i = 0; i < n; ++i)
        {
            if(jolly[i] != i + 1)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
