#include<stdio.h>

int main()
{
    int a, b, c;
    while(scanf(" %d %d %d", &a, &b, &c) == 3)
    {
        if(c == b && a != b)
            printf("A\n");
        else if(a == c && b != a)
            printf("B\n");
        else if(a == b && a != c)
            printf("C\n");
        else
            printf("*\n");
    }
    return 0;
}
