#include<stdio.h>

int main()
{
    unsigned long int x, y;
    while(scanf(" %lu %lu", &x, &y) == 2)
        printf("%lu\n", x^y);
    return 0;
}
