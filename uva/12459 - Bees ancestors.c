#include<stdio.h>

#define MAX 81

long long int fibo[MAX];

int main()
{
    int n;
    fibo[0] = 1;
    fibo[1] = 1;
    for(n = 2; n < MAX; ++n)
        fibo[n] = fibo[n-1] + fibo[n-2];
    while(scanf("%d", &n) == 1 && (n != 0))
        printf("%lld\n", fibo[n]);
    return 0;
}
