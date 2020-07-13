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

#define MX 1005005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

char flag[MX];
ll prime[MX];
int pos;

void sieve()
{
    prime[0] = 2;
    pos = 1;
    for(ll i = 3; i < MX; i+=2)
    {
        if(flag[i]) continue;
        prime[pos++] = i;
        for(ll j = i*i; j < MX; j+=2*i)
        {
            flag[j] = 1;
        }
    }
//    for(int i = 0; i < 100; i++)
//        printf("%d\n", prime[i]);
}

int func(int n, int m)
{
    n = max(2,n);
    if(m<=n) return 0;
    memset(flag,0,sizeof flag);
    for(ll i = 0; i < pos; i++)
    {
        for(ll j = max(2*prime[i],((n+prime[i]-1)/prime[i])*prime[i]); j <= m; j += prime[i])
            flag[j-n] = 1;
    }
    int cnt = 0;
    for(int i = n; i+2 <= m; i++)
        if(flag[i-n] == 0 && flag[i-n+2] == 0) cnt++;
    return cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", func(n,m));
    return 0;
}


