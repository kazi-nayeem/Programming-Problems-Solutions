#include<stdio.h>

int main()
{
    int t, tcount;
    int n, ncount;
    int temp;
    int mile, juice;
    scanf("%d", &t);
    for(tcount = 0; tcount < t;)
    {
        scanf("%d", &n);
        for(ncount = mile = juice = 0; ncount < n; ++ncount)
        {
            scanf("%d", &temp);
            mile += ((temp / 30) + 1) * 10;
            juice += ((temp / 60) + 1) * 15;
        }
        if(mile == juice)
            printf("Case %d: Mile Juice %d\n", ++tcount, mile);
        else if(mile > juice)
            printf("Case %d: Juice %d\n", ++tcount, juice);
        else
            printf("Case %d: Mile %d\n", ++tcount, mile);
    }
    return 0;
}
