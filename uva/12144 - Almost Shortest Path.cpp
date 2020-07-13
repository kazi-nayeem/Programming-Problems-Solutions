#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};

#define MX 505
#define INF 1000000

struct data
{
    int u, w;
    data() {}
    data(int a, int b)
    {
        u = a;
        w = b;
    }
    bool operator <(const data & p) const
    {
        return p.w<w;
    }
};

int dis[MX];
int flag[MX];
vector<data> adj[MX], bac[MX];
int matrix[MX][MX];

void dijkstra(int start, int node)
{
    for(int i = 0; i <= node; i++) dis[i] = INF;
    memset(flag,0,sizeof flag);
    priority_queue<data> qu;
    dis[start] = 0;
    int x, t, p, to;
    qu.push(data(start,0));
    while(!qu.empty())
    {
        x = qu.top().u;
        t = qu.top().w;
        qu.pop();
        if(dis[x] < t || flag[x] == 1) continue;
        flag[x] = 1;
        int sz = adj[x].size();
        for(int i = 0; i < sz; i++)
        {
            p = adj[x][i].u;
            if(matrix[x][p] == 0 || flag[p] == 1) continue;
            to = adj[x][i].w+t;
            if(to >= dis[p]) continue;
            dis[p] = to;
            qu.push(data(p,to));
        }
    }
    return ;
}

void del(int fini)
{
    memset(flag, 0, sizeof flag);
    queue<int> qu;
    qu.push(fini);
    int u, v, w, t;
    while(!qu.empty())
    {
        u = qu.front();
        qu.pop();
        if(flag[u] == 1) continue;
        flag[u] = 1;
        w = dis[u];
        int sz = bac[u].size();
        for(int i = 0; i < sz; i++)
        {
            v = bac[u][i].u;
            t = w-bac[u][i].w;
            if(t != dis[v]) continue;
            qu.push(v);
            matrix[v][u] = 0;
        }
    }
    return;
}

int main()
{
    int start, en, node, edge, u, v, w;
    while(scanf("%d%d", &node, &edge) == 2)
    {
        if(node == 0 && edge == 0) return 0;
        scanf("%d%d", &start, &en);
        for(int i = 0; i <= node; i++)
        {
            adj[i].clear();
            bac[i].clear();
        }
        memset(matrix,0,sizeof matrix);
        for(int i = 0; i < edge; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(data(v,w));
            bac[v].push_back(data(u,w));
            matrix[u][v] = 1;
        }
        dijkstra(start,node);
        //for(int i = 0; i < node; i++)
        //  printf("%d ", dis[i]);
        del(en);
        dijkstra(start,node);
        if(dis[en] != INF)
            printf("%d\n", dis[en]);
        else
            printf("-1\n");
    }
    return 0;
}
