#include<stdio.h>

int main()
{
    int t, n, b;
    int i, j = 1, k = 0;
    double time, memory, downloaded;
    while(scanf("%d%d%d", &t, &n, &b) == 3)
    {
        if(t == 0 && n == 0 && b == 0) break;
        if(k) putchar('\n');
        k = 1;
        for(time = 0.0, i = 0; i < t; i++)
        {
            scanf("%lf%lf", &memory, &downloaded);
            time += memory * (100 - downloaded) / (100 * b);
        }
        printf("Case %d: %.2lf\n", j++, time);
    }
    return 0;
}
