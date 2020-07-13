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

#define MX 105
#define INF 1000

struct data{
        int v;
        double w;
        data(int a, double b) : v(a), w(b){}
        data(int a, int b) : v(a), w(b){}
        bool operator < (const data& p) const
        {
            return w<p.w;
        }
};

vector<data> adj[MX];
double dis[MX];

double dijkstra(int node)
{
    priority_queue<data> qu;
    qu.push(data(0,1.0));
    dis[0] = 100.0;
    int u, v;
    double w, tw;
    while(!qu.empty())
    {
        u = qu.top().v;
        w = qu.top().w;
        qu.pop();

        if(dis[u] < w) continue;
        if(u == node) return w;
        int sz = adj[u].size();
        for(int i = 0; i < sz; i++)
        {
            v = adj[u][i].v;
            tw = w*adj[u][i].w/100;
            if(dis[v] >= tw) continue;
            dis[v] = tw;
            qu.push(data(v,tw));
        }
    }
    return 0.0;
}

int main()
{
    int te, ti, node, edge, siz, k, u, v, w;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d", &node, &edge, &siz, &k);
        for(int i = 0; i <= node; i++)
        {
            adj[i].clear();
            dis[i] = 0;
        }
        for(int i = 0; i < edge; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(data(v,w));
            adj[v].push_back(data(u,w));
        }
        double res = dijkstra(node-1);
        printf("Case %d: %lf\n", te, (double)siz*k*2/res);
    }
    return 0;
}
