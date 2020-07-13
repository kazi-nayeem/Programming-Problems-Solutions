#include<stdio.h>

int main()
{
    int sum, dif, test, total;
    scanf(" %d", &test);
    while(test--)
    {
        scanf(" %d %d", &sum, &dif);
        total = sum + dif;
        if((dif > sum) || (total & 1))
            printf("impossible\n");
        else
        {
            total = total >> 1;
            printf("%d %d\n", total, total - dif);
        }
    }
    return 0;
}
