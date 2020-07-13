#include<stdio.h>

int main()
{
    float c, f;
    int t, count;
    scanf("%d", &t);
    for(count = 1; count<= t; ++count)
    {
        scanf(" %f %f", &c, &f);
        printf("Case %d: %.2f\n", count, c + (5 * f / 9));
    }
    return 0;
}
