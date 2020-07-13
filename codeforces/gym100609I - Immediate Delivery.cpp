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
using namespace std;

#define MX 100005
#define inf 100000000
#define popc __builtin_popcount
typedef long long ll;
typedef unsigned long long ull;

struct data
{
    int u, w;
    data(int a, int b)
    {
        u = a;
        w = b;
    }
    bool operator < (const data &p) const
    {
        return w>p.w;
    }
};

int dist[20][20];
int par[20][20];
int dp[18][1<<18];
int path[18][1<<18];
int node, edge;
vector<data> adj[20];

int func(int u, int mask)
{
    if(popc(mask) == node)
    {
        return 0;
    }
    int & res = dp[u][mask];
    if(res != -1) return res;
    res = inf;
    int &pa = path[u][mask];

    for(int i = 0; i < node; i++)
    {
        if((mask >> i) & 1) continue;
        int tem = func(i,mask | (1<<i))+dist[u][i];
        if(tem < res)
        {
            pa = i;
            res = tem;
        }
    }
    return res;
}


void dijkstra(int s)
{
    for(int i = 0; i <= node; i++) dist[s][i] = inf;

    priority_queue<data> qu;
    qu.push(data(s,0));
    dist[s][s] = 0;
    par[s][s] = s;

    while(!qu.empty())
    {
        int u = qu.top().u;
        int w = qu.top().w;
        qu.pop();

        if(dist[s][u] < w) continue;

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].u;
            int tw = adj[u][i].w + w;

            if(dist[s][v] <= tw) continue;
            par[s][v] = u;
            dist[s][v] = tw;
            qu.push(data(v,tw));
        }
    }
}

vector<int> allpath, mainpath;

void getPath(int u, int mask)
{
    allpath.push_back(u);
    if(popc(mask) == node)
    {
        return;
    }
    int v = path[u][mask];
    getPath(v,mask | (1<<v));
}

void mpath(int u, int v)
{
    if(u == v) return;
    mpath(u,par[u][v]);
    mainpath.push_back(v);
}

int main()
{
    freopen("immediate.in","r",stdin);
    freopen("immediate.out","w",stdout);
    scanf("%d %d", &node, &edge);
    int u, v, w;
    for(int i = 0; i < edge; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        u--;
        v--;
        adj[u].push_back(data(v,w));
        adj[v].push_back(data(u,w));
    }
    for(int i = 0; i < node; i++)
    {
        dijkstra(i);
    }
    /*for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
            printf("%d ", dist[i][j]);
        puts("");
    }
    puts("");
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
            printf("%d ", par[i][j]);
        puts("");
    }*/
    memset(dp,-1,sizeof dp);
    int res = inf;
    int last = (1<<node)-1;
    int pos, sum = -1;
    for(int i = 0; i <= last; i++)
    {
        int tem = func(0,i|1);
        int tem2 = func(0, ((~i)&last) | 1);
        //printf("%d %d\n", i, (~i)&last);

        int r = max(tem2,tem);
        if(res < r) continue;
        if(res > r)
        {
            res = r;
            pos = i;
            sum = tem2+tem;
        }
        if(res == r && sum < tem2+tem)
        {
            pos = i;
            sum = tem2+tem;
        }
    }
    //printf("%d %d\n", pos, sum);
    printf("%d\n", res);

    allpath.clear();
    getPath(0,pos|1);
    mainpath.clear();
    mainpath.push_back(0);
    for(int i = 1; i < allpath.size(); i++)
    {
        mpath(allpath[i-1], allpath[i]);
    }
    printf("%d", mainpath.size()-1);
    for(int i = 0; i < mainpath.size(); i++)
        printf(" %d", mainpath[i]+1);
    puts("");

    allpath.clear();
    getPath(0,((~pos)&last) | 1);
    mainpath.clear();
    mainpath.push_back(0);
    for(int i = 1; i < allpath.size(); i++)
    {
        mpath(allpath[i-1], allpath[i]);
    }
    printf("%d", mainpath.size()-1);
    for(int i = 0; i < mainpath.size(); i++)
        printf(" %d", mainpath[i]+1);
    puts("");
    return 0;
}


