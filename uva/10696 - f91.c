#include<stdio.h>

long int f91(long int n);

int main()
{
    long int n;
    while(scanf(" %ld", &n) == 1)
    {
        if(n == 0) break;
        printf("f91(%ld) = %ld\n", n, f91(n));
    }
    return 0;
}

long int f91(long int n)
{
    if(n > 100)
        return (n - 10);
    return f91( f91( n + 11 ) );
}

