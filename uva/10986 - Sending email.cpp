#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define MX 20005
#define INFI 200000005

struct data{
    int u, c;
    bool operator < (const data& p) const
    {
        return p.c < c;
    }
    data(){}
    data(int a, int b)
    {
        u = a;
        c = b;
    }
};

vector<pair<int, int> > adj[MX];
int distence[MX];

void dijkstra(const int start, const int total);

int main()
{
    int test, time, nodes, edges, start, finish, u, v, w;
    scanf("%d", &time);

    for(test = 1; test <= time; test++)
    {
        scanf("%d %d %d %d", &nodes, &edges, &start, &finish);
        for(int i = 0; i <= nodes; i++)
        {
            adj[i].clear();
            distence[i] = INFI;
        }
        for(int i = 0; i < edges; i++)
        {
            scanf("%d %d %d", &u, &v, &w);

            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        dijkstra(start, nodes);

        if(distence[finish] == INFI)
            printf("Case #%d: unreachable\n", test);
        else
            printf("Case #%d: %d\n", test, distence[finish]);
    }
    return 0;
}

void dijkstra(const int start, const int total)
{
    priority_queue<data> q;
    distence[start] = 0;
    q.push(data(start,distence[start]));

    while(!q.empty())
    {
        int u = q.top().u;
        int c = q.top().c;
        q.pop();

        if(distence[u] < c) continue;

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int nc = adj[u][i].second;

            if(distence[v] <= nc + c) continue;

            distence[v] = nc + c;
            q.push(data(v,distence[v]));
        }
    }

    return;
}

