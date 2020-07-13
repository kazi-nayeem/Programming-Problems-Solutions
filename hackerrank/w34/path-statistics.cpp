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

int arr[MX];
vector<int> adj[MX];
int flag[MX];
map<int,int> mp;

int dfs(int u, int p, int v)
{
    if(u == v)
    {
        mp[arr[u]]++;
        return 1;
    }
    for(int i = 0; i < adj[u].size(); i++)
    {
        int n = adj[u][i];
        if(p == n) continue;
        if(dfs(n,u,v))
        {
            mp[arr[u]]++;
            return 1;
        }
    }
    return 0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q, u, v, k;
    scanf("%d %d", &n, &q);
    for(int i = 1;i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d %d", &u, &v, &k);
        mp.clear();
        dfs(u,u,v);
        vector<pii> vc;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            vc.push_back(make_pair(it->second,it->first));
//            printf("%d %d\n", it->first, it->second);
        }
        sort(vc.begin(), vc.end());
//        for(int i = 0; i < vc.size(); i++)
//            printf("--%d %d\n", vc[i].first, vc[i].second);
        printf("%d\n", vc[vc.size()-k].second);
    }
    return 0;
}


