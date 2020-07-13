#include<stdio.h>
#include<math.h>

#define LLI long long int

LLI bigmod(LLI b, LLI n, LLI m);

int main()
{
    LLI b, n, m;
    while(scanf("%lld %lld %lld", &b, &n, &m) == 3)
        printf("%lld\n", bigmod(b, n, m));
    return 0;
}

LLI bigmod(LLI b, LLI n, LLI m)
{
    if(n == 0) return 1;
    LLI big;
    big = bigmod(b, n/2, m);
    if(n % 2 == 1)
        return ((big % m) * (big % m) * (b % m)) % m;
    return ((big % m) * (big % m)) % m;
}
