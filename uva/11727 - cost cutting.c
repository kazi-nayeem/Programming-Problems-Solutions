#include<stdio.h>

int main()
{
    int t, tcount, x, y, z;
    scanf(" %d", &t);
    for(tcount = 0; tcount < t; )
    {
        scanf("%d %d %d", &x, &y, &z);
        if(x > y)
            x ^= y ^= x ^= y;
        if (x > z)
            x ^= z ^= x ^= z;
        if(y > z)
            z ^= y ^= z ^= y;
        printf("Case %d: %d\n", ++tcount, y);
    }
    return 0;
}
