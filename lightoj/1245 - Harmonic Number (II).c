#include<stdio.h>
#include<math.h>

#define lli long long int

lli cal(lli n);

int main()
{
    lli ti, n, te;
    scanf("%lld", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        printf("Case %d: ", te);
        printf("%lld\n", cal(n));
    }
    return 0;
}

lli cal(lli n)
{
    lli total = 0, root = (lli) sqrt(n);
    lli i;
    for(i = 1; i <= root; i++)
        total += n / i;
    return (total * 2) - (root * root);
}

