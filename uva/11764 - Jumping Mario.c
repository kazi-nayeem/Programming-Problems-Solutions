#include<stdio.h>

int main()
{
    int time, tcount;
    int wells, count;
    int first, second;
    int upper, lower;
    scanf("%d", &time);
    for(tcount = 0; tcount < time ;)
    {
        scanf("%d", &wells);
        if(wells > 0);
        scanf("%d", &first);
        for(count = 1, upper = lower = 0; count < wells; ++count)
        {
            scanf("%d", &second);
            if(first > second)
                lower++;
            else if(first < second)
                upper++;
            first = second;
        }
        printf("Case %d: %d %d\n", ++tcount, upper, lower);
    }
    return 0;
}
