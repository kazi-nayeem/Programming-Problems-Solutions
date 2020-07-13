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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int adj[MX][MX];
int n, m;
int col[MX];
bool flag;

void dfs(int u, int c)
{
    //printf("%d %d\n", u, c);
    if(col[u] != -1)
    {
        if(col[u] != c) {
            flag = false;
        }
        return;
    }
    col[u] = c;
    for(int i = 1; i <= n; i++)
    {
        if(!flag) return;
        if(adj[u][i]) continue;
        dfs(i,c^1);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, u, v;
    scanf("%d", &te);
    while(te--)
    {
        scanf("%d %d", &n, &m);
        memset(adj,0,sizeof adj);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        for(int i = 0; i <= n; i++)
            adj[i][i] = 1;
        memset(col,-1,sizeof col);
        flag = true;
        for(int i = 1; i <= n; i++)
        {
            if(col[i] == -1)
            {
                dfs(i,0);
                if(!flag) break;
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}


