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

#define MX 400005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

vector<int> adj[MX];
int flag[MX];
int a[MX];
int b[MX];

void dfs(int u, int d)
{
    if(flag[u]) return;
    flag[u] = d+1;
    for(int i = 0; i < adj[u].size(); i++)
    {
        dfs(adj[u][i], d^1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
        adj[i*2].push_back(i*2-1);
        adj[i*2-1].push_back(i*2);
    }
    for(int i = 1; i <= 2*n; i++)
        dfs(i,0);
    for(int i = 1; i <= n; i++)
    {
        printf("%d %d\n", flag[a[i]], flag[b[i]]);
    }
    return 0;
}


