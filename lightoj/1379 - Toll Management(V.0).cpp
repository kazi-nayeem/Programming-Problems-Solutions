//C headers
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>

//C++ headers
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

#define MX 10005
#define INF 1000000500

struct data{
    int v, w;
    data(){}
    data(int a, int b)
    {
        v = a;
        w = b;
    }
    bool operator < (const data & p) const
    {
        return p.w < w;
    }
};

vector<data> adj[2][MX];
int dis[2][MX];

void dijkstra(int node, int k);

int main()
{
    int te, ti, node, edge, s, t, p, u, v, w;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d%d", &node, &edge, &s, &t, &p);
        for(int i = 0; i <= node; i++)
        {
            adj[0][i].clear();
            adj[1][i].clear();
            dis[0][i] = INF;
            dis[1][i] = INF;
        }
        for(int i = 0;i < edge; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[0][u].push_back(data(v,w));
            adj[1][v].push_back(data(u,w));
        }
        dijkstra(s,0);
        dijkstra(t,1);
        int mx = -1, sz;
        for(int i = 1; i <= node; i++)
        {
            sz = adj[0][i].size();
            for(int j = 0; j < sz; j++)
            {
                w = adj[0][i][j].w;
                if(w <= mx) continue;
                v = adj[0][i][j].v;
                if(dis[0][i]+w+dis[1][v] <= p)
                    mx = w;
            }
        }
        printf("Case %d: %d\n", te, mx);
    }
    return 0;
}

void dijkstra(int node, int k)
{
    dis[k][node] = 0;
    priority_queue<data> qu;
    qu.push(data(node,0));

    int u, v, w, t;

    while(!qu.empty())
    {
        u = qu.top().v;
        w = qu.top().w;
        qu.pop();

        if(dis[k][u] < w) continue;
        int sz = adj[k][u].size();
        for(int i = 0; i < sz; i++)
        {
            v = adj[k][u][i].v;
            t = adj[k][u][i].w+w;
            if(dis[k][v] <= t) continue;
            dis[k][v] = t;
            qu.push(data(v,t));
        }
    }
    return;
}
