#include<stdio.h>

void ternary(long int n);

int main()
{
    long int n;
    while(scanf("%ld", &n) == 1 && n >= 0)
    {
        if(n == 0)
            printf("0");
        else
            ternary(n);
        printf("\n");
    }
    return 0;
}

void ternary(long int n)
{
    if(n < 1)
        return;
    ternary(n/3);
    printf("%d", n%3);
    return;
}

