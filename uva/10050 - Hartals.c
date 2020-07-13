#include<stdio.h>

#define MAX 3651

int flag[MAX];

int main()
{
    int test;
    int max_day;
    int party, pcount;
    int hortal, i;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d", &max_day, &party);
        for(pcount = 0; pcount < party; ++pcount)
        {
            scanf("%d", &hortal);
            for(i = hortal; i <= max_day; i += hortal)
                flag[i] = 1;
        }
        for(i = 7; i <= max_day; i += 7)
        {
            flag[i] = 0;
            flag[i-1] = 0;
        }
        if(max_day % 7 == 6)
            flag[max_day] = 0;
        for(hortal = 0, i = 1; i <= max_day; ++i)
        {
            if(flag[i])
                {
                    hortal++;
                    flag[i] = 0;
                }
        }
        printf("%d\n", hortal);
    }
    return 0;
}
