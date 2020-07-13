#include<stdio.h>

int main()
{
    int start, thatday, require;
    int extra, total, drink;
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %d %d %d", &start, &thatday, &require);
        for(drink = 0, total = start + thatday; total >= require ; total += extra)
        {
            extra = total % require;
            total = total / require;
            drink += total;
        }
        printf("%d\n", drink);
    }
    return 0;
}
