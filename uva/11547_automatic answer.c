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
        if( n > -1001 && n < 1001){
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        n /= 10;
        printf("%ld\n", n);
        n %= 10;
        printf("%ld\n", n);
    }
    }
    return 0;
}
