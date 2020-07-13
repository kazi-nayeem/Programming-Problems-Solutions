#include<stdio.h>

int main()
{
    long long int n, m;
    long long int i, j, max, count;
    scanf("%lld %lld", &n, &m);
    for(max = 0, i = n; i <= m ; ++i)
    {
        j = i;
        for(count = 1 ; j != 1; count++)
        if( j % 2 == 1)
        j = 3 * j + 1;
        else
        j /= 2;
        if(count > max)
        max = count;
     }
    printf("%lld %lld %ld\n", n, m, max);
    return 0;
}
