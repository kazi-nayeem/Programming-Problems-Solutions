#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define ll long long int
typedef pair<ll,ll> pll;

char str[15];
int len;
pll dp[11][2];

pll func(int pos, int flag);

int main()
{
    ll res, a, b;
    while(scanf("%lld%lld", &a, &b) == 2)
    {
        if(a == 0 && b == 0) return 0;
        res = 0;
        if(a > 0)
        {
            memset(dp, -1, sizeof dp);
            sprintf(str, "%lld", a-1);
            len = strlen(str);
            //printf("%d\n", len);
            res -= func(0,1).first;
        }
        if(b > 0)
        {
            memset(dp, -1, sizeof dp);
            sprintf(str, "%lld", b);
            len = strlen(str);
            //printf("%d\n", len);
            res += func(0,1).first;
        }
        printf("%lld\n", res);
    }
    return 0;
}

pll func(int pos, int flag)
{
    if(pos == len)
        return make_pair(0,1);
    if(dp[pos][flag].first != -1)
        return dp[pos][flag];

    dp[pos][flag] = make_pair(0,0);

    pll tem;
    ll sum = 0, sol = 0;
    int mx = (flag)? (str[pos]-'0'):9;
    for(int i = 0; i <= mx; i++)
    {
        tem = func(pos+1,flag && (i == mx));
        sum += i * tem.second + tem.first;
        sol += tem.second;
    }
    return dp[pos][flag] = make_pair(sum,sol);
}
