#include<stdio.h>

int main()
{
    int t, test;
    int x1, x2, y, r;
    scanf(" %d", &t);
    for(test = 0; test < t;)
    {
        scanf(" %d", &r);
        y = 3 * r / 2;
        x1 = 9 * r / 4;
        x2 = 11 * r / 4;
        printf("Case %d:\n", ++test);
        printf("-%d %d\n", x1, y);
        printf("%d %d\n", x2, y);
        printf("%d -%d\n", x2, y);
        printf("-%d -%d\n", x1, y);
    }
    return 0;
}
