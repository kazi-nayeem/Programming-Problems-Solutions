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
#define MX2 1005
#define inf 100000000

const ll mod = 1000000007ll;

vector<int> adj[MX];
int flag[MX];
int now;

void dfs(int u)
{
    if(flag[u] != 0) return;
    flag[u] = now;
    for(int i = 0; i < adj[u].size(); i++)
        dfs(adj[u][i]);
}

int arr[MX2];
int dp[MX2][MX2];

int func(int i, int j)
{
    if(i>j) return 0;
    if(i == j) return 1;
    int & res = dp[i][j];
    if(res != -1) return res;
    res = max(func(i+1,j),func(i,j-1));
    if(arr[i] == arr[j]) res = max(res,func(i+1,j-1)+2);
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, m, u, v;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < k; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i <= n; i++)
        if(flag[i] == 0) now++, dfs(i);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &arr[i]);
        arr[i] = flag[arr[i]];
    }
    memset(dp,-1,sizeof dp);
    printf("%d\n", func(1,m));
    return 0;
}


