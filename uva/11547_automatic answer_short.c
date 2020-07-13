#include<stdio.h>

int main()
{
    unsigned short int t, tcount;
    long int n;
    scanf(" %d", &t);
    if(t >0 && t < 101)
    for(tcount = 0; tcount < t; ++tcount)
    {
        scanf(" %ld", &n);
        if( n > -1001 && n < 1001)
        {
            n = ( n * 315 ) + 36962;
            n /= 10;
            n %= 10;
            if(n < 0)
                printf("%ld\n", -n);
            else
                printf("%ld\n", n);
        }
    }
    return 0;
}

