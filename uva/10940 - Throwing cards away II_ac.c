#include<stdio.h>
#include<math.h>

int main()
{
    long int n, lo, t;
    while(scanf("%ld", &n) == 1)
    {
        if(n == 0) return 0;
        for(t = 1; t <= n; t <<=1);
        t %= n;
        n = n - t;
        printf("%ld\n", n);
    }
    return 0;
}

