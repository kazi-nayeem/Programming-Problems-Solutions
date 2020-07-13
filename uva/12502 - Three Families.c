#include<stdio.h>

int main()
{
    int x, y, z;
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %d %d %d", &x, &y, &z);
        z = z * ((2 * x) - y) / (x + y);
        printf("%d\n", z);
    }
    return 0;
}
