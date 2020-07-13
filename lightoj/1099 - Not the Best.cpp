#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define MX 5005
#define INFI 26000000

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
int dist1[MX];
int dist2[MX];

int dijkstra(const int node);

int main()
{
    int time, test, nodes, edges, a, b, c, dis;

    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d %d", &nodes, &edges);

        for(int i = 0; i <= nodes; i++)
        {
            dist1[i] = INFI;
            dist2[i] = INFI;
            adj[i].clear();
        }

        for(int i = 0; i < edges; i++)
        {
            scanf("%d %d %d", &a, &b, &c);

            adj[a].push_back(data(b,c));
            adj[b].push_back(data(a,c));
        }

        printf("Case %d: %d\n", test, dijkstra(nodes));
    }
    return 0;
}

int dijkstra(const int node)
{
    priority_queue<data> que;
    int u, v, w, co;

    dist1[1] = 0;
    que.push(data(1,dist1[1]));

    while(!que.empty())
    {
        u = que.top().node;
        w = que.top().weight;
        que.pop();

        if(dist2[u] < w) continue;

        int sz = adj[u].size();

        for(int i = 0; i < sz; i++)
        {
            v = adj[u][i].node;
            co = adj[u][i].weight;
            co = co+w;

            if(dist2[v] <= co || dist1[v] == co) continue;
            if(dist1[v] > co)
            {
                dist2[v] = dist1[v];
                dist1[v] = co;
                que.push(data(v,dist1[v]));
            }
            else
            {
                dist2[v] = co;
                que.push(data(v,dist2[v]));
            }
        }
    }
    if(dist2[node] == INFI) return dist1[node];
    return dist2[node];
}


