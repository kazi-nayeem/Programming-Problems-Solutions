#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
#define MX 1000005

const ll mod = 1000000007;

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0) return 1;
    ll res = bigmod(a,p/2,m);
    res = (res*res)%m;
    if((p%2ll) == 1ll)
        res = (res*a)%m;
    return res;
}

ll fact[MX];
vector<int> vc;

int main()
{
    fact[0] = 1;
    for(ll i = 1; i < MX; i++)
        fact[i] = (fact[i-1]*i)%mod;
    int a, b, n;
    ll res = 0;
    scanf("%d%d%d", &a, &b, &n);
    vc.push_back(0);
    int mx = b*n;
    for(int i = 0; i < vc.size(); i++)
    {
        if((10*vc[i] + a) <= mx)
            vc.push_back(10*vc[i] + a);
        if((10*vc[i] + b) <= mx)
            vc.push_back(10*vc[i] + b);
    }
    sort(vc.begin(),vc.end());
    vc.resize(distance(vc.begin(),unique(vc.begin(),vc.end())));
    for(int i = 1; i < vc.size(); i++)
    {
        //printf("%d\n", vc[i]);
        if((mx-vc[i])%(b-a)) continue;
        int x = (mx-vc[i])/(b-a);
        if(x < 0 || n < x) continue;
        ll tem = fact[n];
        tem *= bigmod(fact[x],mod-2,mod);
        tem %= mod;
        tem *= bigmod(fact[n-x],mod-2,mod);
        tem %= mod;
        res = (res+tem)%mod;
    }
    printf("%I64d\n", res);
    return 0;
}

