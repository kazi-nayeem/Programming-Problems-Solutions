#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define MX 505
#define INFI 200000

struct data{
        int node, weight;

        bool operator < (const data& p) const
        {
            return p.weight < weight;
        }
        data(){}
        data(int a, int b)
        {
            node = a;
            weight = b;
        }
};

vector<data> adj[MX];
int dist[MX];

void dijkstra(const int start, const int nodes);

int main()
{
    int time, test, nodes, edges, start, a, b, c;

    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d %d", &nodes, &edges);

        for(int i = 0; i <= nodes; i++)
        {
            dist[i] = INFI;
            adj[i].clear();
        }

        for(int i = 0; i < edges; i++)
        {
            scanf("%d %d %d", &a, &b, &c);

            adj[a].push_back(data(b,c));
            adj[b].push_back(data(a,c));
        }
        scanf("%d", &start);

        dijkstra(start, nodes);

        printf("Case %d:\n", test);

        for(int i = 0; i < nodes; i++)
        {
            if(dist[i] == INFI)
                printf("Impossible\n");
            else
                printf("%d\n", dist[i]);
        }
    }
    return 0;
}

void dijkstra(const int start, const int nodes)
{
    priority_queue<data> que;
    int u, v, w, visit = 0, co;

    dist[start] = 0;
    que.push(data(start,dist[start]));

    while(!que.empty())
    {
        u = que.top().node;
        w = que.top().weight;
        que.pop();

        if(dist[u] < w) continue;
        visit++;
        if(visit == nodes) return;

        int sz = adj[u].size();

        for(int i = 0; i < sz; i++)
        {
            v = adj[u][i].node;
            co = adj[u][i].weight;
            co = (co>w)? co:w;

            if(dist[v] <= co) continue;

            dist[v] = co;
            que.push(data(v,dist[v]));
        }
    }
    return;
}
