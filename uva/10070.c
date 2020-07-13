#include<stdio.h>

int main()
{
    long long int year;
    int flag;
    while(scanf("%lld", &year)==1)
    {
        flag = 0;
        if(year % 400 == 0)
        {
            printf("This is leap year.\n");
            flag = 1;
        }
        else if(year % 100 == 0);
        else if(year % 4 == 0)
        {
            printf("This is leap year.\n");
            flag = 1;
        }
        if(year % 15 == 0)
        {
            printf("This is huluculu festival year.\n");
            flag = 1;
        }
        if(year % 55 == 0)
        {
            printf("This is bulukulu festival year.\n");
            flag = 1;
        }
        if(flag == 0)
        printf("This is an ordinary year.\n");
        printf("\n");
    }
    return 0;
}
