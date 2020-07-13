#include<stdio.h>

int gcd(int i, int j);

int main()
{
    unsigned int i, j, n, t;
    unsigned long int g;
    scanf("%u", &n);
    for(t = 0, g = 0;t < 100 && n != 0 ; ++t, g = 0)
    {
        for(i = 1; i < n ; ++i)
        for(j = i + 1 ; j <= n ; ++j)
            g += gcd(i,j);
        printf("%lu\n", g);
        scanf("%u", &n);
    }
    return 0;
}

int gcd(int i, int j)
{
    if( i % j == 0)
        return j;
    return(gcd(j, i % j));
}
