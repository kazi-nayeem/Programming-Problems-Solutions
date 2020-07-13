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

vector<int> adj[MX];
int arr[MX];
int dist[MX];

int dfs(int u)
{
    dist[u] = 1;
    for(int i = 0; i < adj[u].size(); i++)
    {
        dist[u] = dfs(adj[u][i])^1;
    }
    return dist[u];
}

map<int,int> mp[2];
int cnt[2];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        adj[x].push_back(i);
    }
    dfs(1);
    int game = 0;
    for(int i = 1; i <= n; i++)
    {
        game ^= arr[i]*dist[i];
        //printf("%d\n", dist[i]);
        //mp[0][arr[i]] = 0;
        //mp[1][arr[i]] = 0;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
//        if(mp[0].find(arr[i]) == mp[0].end())
//            mp[0][arr[i]] = 0;
//        if(mp[1].find(arr[i]) == mp[1].end())
//            mp[1][arr[i]] = 0;
       // printf("%d %d %d\n", i, dist[i], arr[i]);
        if(dist[i] == 0)
        {
            if(game == 0) ans += cnt[0] + mp[1][arr[i]];
            else
            {
                int now = game^arr[i];
                ans += mp[1][now];
            }
        }
        else
        {
            if(game == 0) ans += cnt[1] +mp[0][arr[i]];
            else
            {
                int now = game^arr[i];
                ans += mp[0][now];
            }
        }
        //printf("%lld\n", ans);
        mp[dist[i]][arr[i]]++;
        cnt[dist[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}


