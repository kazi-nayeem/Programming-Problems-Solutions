#include<stdio.h>

#define ll long long

int main()
{
    ll n;
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        int mod = n%9;
        printf("Case %d:", te);
        if(mod == 0)
            printf(" %lld %lld\n", n+(n/9)-1, n+n/9);
        else
            printf(" %lld\n", n+n/9);
    }
    return 0;
}
