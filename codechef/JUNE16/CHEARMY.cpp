//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

char str[1000];

int dp[100];

int func(int len)
{
    if(len == -1) return 1;
    int & res = dp[len];
    if(res != -1) return res;
    res = func(len-1)*(str[len]-'0'+1);
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*for(int i = 0; i < 1000000; i++)
    {
        sprintf(str,"%d", i);
        memset(dp,-1,sizeof dp);
        if(((func(strlen(str)-1)-1) %2 )== 0)
            printf("%d \n", i, func(strlen(str)-1)-1);
    }*/
    int te, ti;
    scanf("%d", &ti);
    while(ti--)
    {
        ll n;
        scanf("%lld", &n);
        if(n == 1)
        {
            puts("0");
            continue;
        }
        int res = 0;
        n--;
        bool flag = true;
        while(n>0)
        {
            str[res++] = (n%5)*2+'0';
            n /= 5;
            //n++;
        }
        str[res] = 0;
        //puts(str);
        reverse(str,str+res);
        puts(str);
    }
    return 0;
}


