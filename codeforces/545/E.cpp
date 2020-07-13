#include <bits/stdc++.h>

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
using namespace std;

#define MX 300005
#define inf 500000000000000000ll

typedef long long ll;
typedef unsigned long long ull;

struct data
{
    int v;
    ll w;
    data(int a, ll b)
    {
        v = a;
        w = b;
    }
    bool operator < (const data & p) const
    {
        return w>p.w;
    }
};

map<pair<int,int>, pair<int,ll> > mp;

vector<data> adj[MX];
ll dis[MX];
int node, edge;
priority_queue<data> qu;

void func(int u)
{
    for(int i = 0; i <= node; i++) dis[i] = inf;
    dis[u] = 0ll;

    while(!qu.empty()) qu.pop();

    qu.push(data(u,0ll));
    while(!qu.empty())
    {
        int u = qu.top().v;
        ll w = qu.top().w;
        qu.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v;
            ll tw = adj[u][i].w+w;
            if(dis[v] > tw)
            {
                dis[v] = tw;
                qu.push(data(v,tw));
            }
        }
    }
}

vector<int> res;

int main()
{
    scanf("%d%d", &node, &edge);
    for(int i = 1; i <= edge; i++)
    {
        int u, v;
        ll w;
        scanf("%d %d %I64d", &u, &v, &w);
        adj[u].push_back(data(v,w));
        adj[v].push_back(data(u,w));
        mp[make_pair(u,v)] = make_pair(i,w);
        mp[make_pair(v,u)] = make_pair(i,w);
    }
    int u;
    scanf("%d", &u);
    func(u);
    ll total = 0;
    for(int i = 1; i <= node; i++)
    {
        int u = -1;
        ll w = inf;
        for(int j = 0; j < adj[i].size(); j++)
        {
            ll tw = adj[i][j].w;
            int v = adj[i][j].v;
            if(dis[v]+tw == dis[i] && w > tw)
            {
                w = tw;
                u = v;
            }
        }
        //printf("%d %d\n", i, u);
        if(u != -1)
        {
            res.push_back(mp[make_pair(i,u)].first);
            total += mp[make_pair(i,u)].second;
        }
    }
    sort(res.begin(),res.end());
    printf("%I64d\n", total);
    for(int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
    return 0;
}

