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

string arr[MX];
int flag[MX];
int dis[MX];
vector<int> adj[MX];
map<string,int> mp;

void dfs(int u) {
    if(dis[u]) return;
    dis[u] = 1;
    for(int i = 0; i < adj[u].size(); i++)
        dfs(adj[u][i]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, u, v, m;
    scanf("%d", &ti);
    while(ti--) {
        scanf("%d %d %d", &u, &v, &m);
        mp.clear();
        memset(flag,0,sizeof flag);
        memset(dis,0,sizeof dis);
        for(int i = 0; i < MX; i++)
            adj[i].clear();
        for(int i = 1; i <= u; i++) {
            string a;
            cin>>a;
            if(mp.find(a) == mp.end()) {
                mp[a] = mp.size();
                arr[mp[a]] = a;
            }
        }
        for(int i = 1; i <= v; i++) {
            string a;
            cin>>a;
            if(mp.find(a) == mp.end()) {
                mp[a] = mp.size();
                arr[mp[a]] = a;
            }
            flag[mp[a]] = 1;
        }
        for(int i = 1; i <= m; i++) {
            string a, b;
            cin>>a>>b;
            if(mp.find(a) == mp.end()) {
                mp[a] = mp.size();
                arr[mp[a]] = a;
            }
            if(mp.find(b) == mp.end()) {
                mp[b] = mp.size();
                arr[mp[b]] = b;
            }
            adj[mp[a]].push_back(mp[b]);
        }
        for(int i = 1; i <= u; i++) {
            dfs(i);
        }
        vector<string> res;
        for(int i = 1; i <= mp.size(); i++) {
            if(flag[i] == 1 && dis[i] == 1) {
                res.push_back(arr[i]);
            }
        }
        sort(res.begin(),res.end());
        if(res.size()) cout<<res[0];
        for(int i = 1; i < res.size(); i++)
            cout<<" "<<res[i];
        puts("");
    }
    return 0;
}

