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

const ll mod = 2000000000ll;

ll arr1[MX];
ll arr2[MX];
int n, m;
ll k;

int func(ll add)
{
    int ans = 0;
    int pos = 1;
    for(int i = 1; i <= n; i++)
    {
        ll now = arr1[i]+add;
        while(pos < m && arr2[pos] < now-k) pos++;
        if(pos <= m && abs(arr2[pos]-now) <= k)
        {
            ans++;
            pos++;
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d %lld", &n, &m, &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr1[i]);
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%lld", &arr2[i]);
        }
        sort(arr1+1,arr1+1+n);
        sort(arr2+1,arr2+1+m);
        int ans = func(0);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                ll add = arr1[i]-arr2[j]+k;
                add = max(add,-mod);
                add = min(add,mod);
                ans = max(ans,func(add));
                add = arr1[i]-arr2[j]-k;
                add = max(add,-mod);
                add = min(add,mod);
                ans = max(ans,func(add));
            }
        printf("%d\n", ans);
    }
    return 0;
}


