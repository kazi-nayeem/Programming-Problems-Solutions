#include<stdio.h>

int main()
{
    int a;
    while(scanf(" %d", &a) == 1)
    {
        if(a%6)
            printf("N\n");
        else
            printf("Y\n");
    }
    return 0;
}
