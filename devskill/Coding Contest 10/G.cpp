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

map<int,bool> mp[MX];
char str[MX];
int n, len;

bool func(int const mask, int const pos)
{
    if(mp[pos].find(mask) != mp[pos].end()) return mp[pos][mask];
    if(pos == len)
    {
        if(mask+1 == (1<<n)) return true;
        return false;
    }
    mp[pos][mask] = false;
    int a;
    sscanf(str+pos,"%1d", &a);
    if( a<=n && a > 0)
    {
        if((mask>>(a-1))&1)
        {

        }
        else
        {
            mp[pos][mask] = func(mask|(1<<(a-1)),pos+1);
            if(mp[pos][mask]) return true;
        }

    }


    if(pos+1<len)
    {
        sscanf(str+pos,"%2d", &a);
        if( a<=n && a > 0)
        {
            if((mask>>(a-1))&1)
            {

            }
            else
            {
                mp[pos][mask] = func(mask|(1<<(a-1)),pos+2);
                if(mp[pos][mask]) return true;
            }
        }
    }
    return mp[pos][mask];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %s", &n, str);
        len = strlen(str);
        for(int i = 0; i <= len; i++)
            mp[i].clear();
        if(func(0,0))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

