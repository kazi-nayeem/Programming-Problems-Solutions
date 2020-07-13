#include<stdio.h>

int main()
{
    long long int a, b, c, d;
    long long int time;
    scanf("%lld", &time);
    while(time--)
    {
        scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
        if(a == 0 || b == 0 || c == 0 || d == 0)
            printf("banana\n");
        else if(a == b && b == c && c == d)
            printf("square\n");
        else if((a+b+c>d) && (a+b+d>c) && (a+c+d > b) && (b+c+d > a))
        {
            if((a == b && c == d)||(a == c && b == d) || (a == d && b == c))
                    printf("rectangle\n");
            else
                printf("quadrangle\n");
        }
        else
        printf("banana\n");
    }
    return 0;
}
