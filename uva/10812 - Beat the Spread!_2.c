#include<stdio.h>

int main()
{
    int sum, dif, test, total;
    scanf(" %d", &test);
    while(test--)
    {
        scanf(" %d %d", &sum, &dif);
        total = sum + dif;
        if((dif > sum) || (total%2))
            printf("impossible\n");
        else
            printf("%d %d\n", total/2, total/2 - dif);
    }
    return 0;
}

