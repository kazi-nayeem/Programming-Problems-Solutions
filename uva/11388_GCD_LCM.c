#include<stdio.h>

int main()
{
    long int gcd, lcm, j;
    int t;
    scanf(" %d", &t);
    for(;t > 0; --t)
    {
        scanf(" %ld %ld", &gcd, &lcm);
        j = lcm / gcd;
        if(j * gcd == lcm)
            printf("%ld %ld\n", gcd, lcm);
        else
            printf("-1\n");
    }
    return 0;
}
