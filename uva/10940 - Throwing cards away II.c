#include<stdio.h>
#include<math.h>

int main()
{
    long int n, lo, t;
    while(scanf("%ld", &n) == 1)
    {
        if(n == 0) return 0;
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        for(t = 1; t < n; t <<=1);
        t >>= 1;
        n = (n - t) * 2;
        printf("%ld\n", n);
    }
    return 0;
}
