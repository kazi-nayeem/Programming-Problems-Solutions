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

const ll mod = 1000000007ll;

ll sqr(ll a)
{
    return a*a;
}

ll sqdis(pll a, pll b)
{
    return sqr(a.first-b.first)+sqr(a.second-b.second);
}

ll res;

pll arr[MX];
ll radius[MX];
vector<int> adj[MX];
int flag[MX];

void dfs(int u, int v)
{
    flag[u] = 1;
    res += sqr(radius[u])*v;
    //printf(">>>%d %d\n", u, v);
    for(int i = 0; i < adj[u].size(); i++)
        dfs(adj[u][i],-v);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld %lld %lld", &arr[i].first, &arr[i].second, &radius[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int par = -1;
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(radius[j]<=radius[i]) continue;
            if(sqdis(arr[i],arr[j])>sqr(radius[j])) continue;
            if(par == -1 || radius[j]<radius[par]) par = j;
        }
        if(par != -1)
            adj[par].push_back(i);
        else flag[i] = -1;
        //printf("%d %d\n", i, par);
    }
    for(int i = 0; i < n; i++)
        if(flag[i] == -1) dfs(i,-1), res += 2*sqr(radius[i]);
    printf("%.10lf\n", acos(-1)*res);
    return 0;
}


