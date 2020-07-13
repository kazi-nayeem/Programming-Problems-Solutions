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
#define INF 100050000

struct data{
        int v, w, p;
        data(){}
        data(int a, int b, int c) : v(a), w(b), p(c){}
        bool operator <(const data& p) const
        {
            return p.w<w;
        }
};

vector<data> adj[MX];
int dis[MX][11];

int dijkstra(int node, int mx);

int main()
{
    int te, ti, node, edge1, edge2, u, v, w, k;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d%d", &node, &edge1, &edge2, &k);
        for(int i = 0; i <= node; i++)
        {
            adj[i].clear();
            for(int j = 0; j <= k; j++)
                dis[i][j] = INF;
        }
        for(int i = 0; i < edge1; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(data(v,w,0));
        }
        for(int i = 0; i < edge2; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(data(v,w,1));
        }
        int res = dijkstra(node-1,k);
        if(res != -1)
            printf("Case %d: %d\n", te, res);
        else
            printf("Case %d: Impossible\n", te);
    }
    return 0;
}

int dijkstra(int node, int mx)
{
    priority_queue<data> qu;
    qu.push(data(0,0,0));
    dis[0][0] = 0;

    int u, v, w, p, tw, tp;

    while(!qu.empty())
    {
        u = qu.top().v;
        w = qu.top().w;
        p = qu.top().p;
        qu.pop();
        //printf("%d %d %d ", u, w, p);
        if(u == node) return w;
        if(dis[u][p] < w) continue;
        int sz = adj[u].size();
        //printf("%d\n", sz);
        for(int i = 0; i < sz; i++)
        {
            v = adj[u][i].v;
            tw = adj[u][i].w+w;
            tp = adj[u][i].p+p;
            //printf("dis[%d][%d] = %d %d\n", v, tp, dis[v][tp], tw);
            if(tp>mx || dis[v][tp] <= tw) continue;
            dis[v][tp] = tw;
            qu.push(data(v,tw,tp));
        }
    }
    return -1;
}
