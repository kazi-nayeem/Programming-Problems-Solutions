#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define MX 1000005
#define lli long long int

lli dp[MX];

lli fun(lli n);

int main()
{
    memset(dp,-1,sizeof dp);
    lli n;
    while(scanf("%lld", &n) == 1)
    {
        if(n == -1) return 0;
        printf("%lld\n", fun(n));
    }
    return 0;
}

lli fun(lli n)
{
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    lli res = fun(floor((double)n - sqrt(n)));
    res += fun((lli)floor(n*sin(n)*sin(n)));
    res += fun((lli)floor(log(n)));
    return dp[n] = res % 1000000ll;
}
