#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long

ll dp[1005];

ll func(int n)
{
    if(n == 0 || n == 1) return 1;
    ll & res = dp[n];
    if(res != -1) return res;
    res = 0;
    for(int i = 0; i < n; i++)
        res += func(i)*func(n-i-1);
    return res;
}

int main()
{
    memset(dp,-1,sizeof dp);
    ll n;
    while(scanf("%lld", &n) == 1)
    {
        int i;
        for(i = 1; func(i) < n; i++);
        printf("%d\n", i);
    }
    return 0;
}

