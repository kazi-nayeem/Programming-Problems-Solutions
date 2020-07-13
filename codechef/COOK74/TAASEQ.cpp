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

const ll mod = 1000000000000007ll;

bool finc(vector<ll> ar)
{
    int sz = ar.size();
    if(sz == 1) return true;
    ll dif = ar[1]-ar[0];
    for(int i = 1; i < sz; i++)
    {
        if(ar[i]-ar[i-1] != dif) return false;
    }
    return true;
}

ll arr[MX];
vector<ll> tem;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, n;
    ll x, res;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        res = mod+100;
        tem.clear();
        for(int i = 1; i < n; i++)
        {
            tem.push_back(arr[i]);
        }
        if(finc(tem))
        {
            res = min(res,arr[0]);
        }

        tem.clear();
        tem.push_back(arr[0]);
        for(int i = 2; i < n; i++)
        {
            tem.push_back(arr[i]);
        }
        if(finc(tem))
        {
            res = min(res,arr[1]);
        }

        int con = 0;
        ll t;
        ll pre = arr[1];
        ll dif = arr[1]-arr[0];
        for(int i = 2; i < n; i++)
        {
            if(dif != arr[i]-pre)
            {
                con++;
                t = arr[i];
            }
            else
            {
                pre = arr[i];
            }
        }
        if(con == 0)
        {
            res = min(res,min(arr[0],arr[n-1]));
        }
        else if(con == 1)
        {
            res = min(res,t);
        }
        if(res>=mod) res = -1;
        printf("%lld\n", res);
    }
    return 0;
}


