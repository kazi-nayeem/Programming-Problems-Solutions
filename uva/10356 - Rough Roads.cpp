#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MX 503
#define INFI 200000

struct data{
        int u, w, c;

        bool operator < (const data& p) const
        {
            return p.w < w;
        }

        data(int a, int b, int co)
        {
            u = a, w = b, c = co;
        }
};

vector<pair<int , int> > adj[MX];
int dist[2][MX];

int dijkstra(const int node);

int main()
{
    int test = 1, node, edge, u, v, w;

    while(scanf("%d %d", &node, &edge) == 2)
    {
        for(int i = 0; i <= node; i++)
        {
            adj[i].clear();
            dist[0][i] = INFI;
            dist[1][i] = INFI;
        }

        for(int i = 0; i < edge; i++)
        {
            scanf("%d %d %d", &u, &v, &w);

            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        int di = dijkstra(node-1);

        if(di == -1)
            printf("Set #%d\n?\n", test++);
        else
            printf("Set #%d\n%d\n", test++, di);
    }

    return 0;
}

int dijkstra(const int node)
{
    priority_queue<data> qu;
    int u, v, c, w, t;

    qu.push(data(0,0,0));
    dist[0][0] = 0;

    while(!qu.empty())
    {
        u = qu.top().u;
        w = qu.top().w;
        c = qu.top().c;
        qu.pop();

        if(dist[c][u] < w) continue;
        if(u == node && c == 0) return dist[c][node];

        c = (c+1) & 1;

        int sz = adj[u].size();

        for(int i = 0; i < sz; i++)
        {
            v = adj[u][i].first;
            t = w + adj[u][i].second;

            if(t >= dist[c][v]) continue;

            dist[c][v] = t;
            qu.push(data(v,t,c));
        }
    }
    return -1;
}
