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

int arr[100];
int dp_cas[1<<15];
bool dp[1<<15];
int te, ti, n;

bool func(int mask)
{
    int &cas = dp_cas[mask];
    bool &res = dp[mask];
    if(cas == te) return res;
    cas = te;
    int pre = 0;
    res = true;
    for(int i = 0; i < n; i++)
    {
        if((mask>>i)&1)
        {
            if(arr[i] < pre)
            {
                res = false;
                break;
            }
            else
            {
                pre = arr[i];
            }
        }
    }
    if(res)
    {
        res = false;
        return res;
    }
    res = false;
    for(int i = 0; i < n; i++)
    {
        if((mask>>i)&1)
        {
            res = !func(mask-(1<<i));
            if(res) break;
        }
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if(func((1<<n)-1))
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}


