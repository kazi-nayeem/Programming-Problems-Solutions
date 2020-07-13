#include<stdio.h>

int main()
{
    int h1, h2, m1, m2;
    int sleep;
    while(scanf(" %d %d %d %d", &h1, &m1, &h2, &m2) == 4)
    {
        if(h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0) break;
        sleep = 60 * (h2 - h1) + m2 - m1;
        if(sleep < 0)
        sleep += 1440;
        printf("%d\n", sleep);
    }
    return 0;
}
