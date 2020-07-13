#include <bits/stdc++.h>

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

map<ll,int> mp;
priority_queue<ll> qu;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    ll v;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &v);
        ++mp[v];
    }
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        qu.push(it->first);
    }
    int pre = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%lld", &v);
        while(pre+mp[qu.top()]<v)
        {
            ll p = qu.top();
            qu.pop();
            int cnt = mp[p];
            pre += cnt;
            //mp[p] = 0;
            p /= 2;
            if(p>0)
            {
                if(mp.find(p) == mp.end())
                {
                    //mp[p] = 0;
                    qu.push(p);
                }
                mp[p] += cnt;
            }
        }
        printf("%lld\n", qu.top());
    }
    return 0;
}


