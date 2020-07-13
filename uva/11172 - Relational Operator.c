#include<stdio.h>

int main()
{
    int t, tcount;
    long long int a, b;
    scanf(" %d", &t);
    for( tcount = 0; tcount < t ; tcount++)
    {
        scanf(" %lld %lld", &a, &b);
        if(a > b)
            printf(">\n");
        else if(a == b)
            printf("=\n");
        else
            printf("<\n");
    }
    return 0;
}

