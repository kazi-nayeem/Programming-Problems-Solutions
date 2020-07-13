#include<stdio.h>
#include<string.h>

int main()
{
    char operation[7];
    int total = 0, time, donate;
    scanf("%d", &time);
    while(time--)
    {
        scanf(" %6s", operation);
        if(strcmp(operation, "donate") == 0)
            {
                scanf(" %d", &donate);
                total += donate;
            }
        else
            printf("%d\n", total);
    }
    return 0;
}
