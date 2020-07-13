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

vector<pll> arr[MX];
map<ll,int> mp;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m;
    int k;
    scanf("%lld %lld %d", &n, &m, &k);
    ll res = n*m;
    for(int i = 1; i <= k; i++)
    {
        ll r, c1, c2;
        scanf("%lld %lld %lld", &r, &c1, &c2);
        if(mp.find(r) == mp.end())
        {
            mp[r] = mp.size();
        }
        arr[mp[r]].push_back(make_pair(c1,c2));
    }
    for(int i = 1; i <= mp.size(); i++)
    {
        sort(arr[i].begin(),arr[i].end());
        ll prev = -1000;
        for(int j = 0; j < arr[i].size(); j++)
        {
            prev = max(prev,arr[i][j].first);
            if(prev<=arr[i][j].second)
            {
                res -= arr[i][j].second-prev+1;
                prev = arr[i][j].second+1;
            }
        }
    }
    printf("%lld\n", res);
    return 0;
}


