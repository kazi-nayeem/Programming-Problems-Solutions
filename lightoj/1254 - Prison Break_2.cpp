#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define INF 10000000

struct data{
    int nod, cost, fuel;
    data(){}
    data(int a, int b, int c)
    {
        nod = a,cost = b,fuel = c;
    }
    bool operator < (const data & p) const
    {
        return p.cost < cost;
    }
};

struct data1{
    int nod, cost;
    data1(){}
    data1(int a, int b)
    {
        nod = a,cost = b;
    }
};

int oil[105], arr[101][101];
vector<data1> adj[101];

int dijkstra(int start, int finish, int cafuel);

int main()
{
    int node, edge, te, ti, q, u, v, w;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &node, &edge);
        for(int i = 0; i < node; i++)
        {
            adj[i].clear();
            scanf("%d", oil+i);
        }
        for(int i = 0; i < edge; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(data1(v,w));
            adj[v].push_back(data1(u,w));
        }
        printf("Case %d:\n", te);
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d %d %d", &w, &u, &v);
            for(int j = 0; j < node; j++)
                for(int k = 0; k <= w; k++)
                    arr[j][k] = INF;

            int total = dijkstra(u, v, w);
            if(total == -1)
                printf("impossible\n");
            else
                printf("%d\n", total);
        }
    }
    return 0;
}

int dijkstra(int start, int finish, int cafuel)
{
    priority_queue<data> que;
    int node, cost, fuel, ne_node, ne_cost, ne_fuel, total;

    for(int i = 0; i <= cafuel; i++)
        arr[start][i] = i*oil[start], que.push(data(start,arr[start][i],i));

    while(!que.empty())
    {
        node = que.top().nod;
        cost = que.top().cost;
        fuel = que.top().fuel;
        que.pop();
        if(node == finish) return cost;
        if(arr[node][fuel] > cost) continue;

        int sz = adj[node].size();

        for(int i = 0; i < sz; i++)
        {
            ne_node = adj[node][i].nod;
            ne_cost = adj[node][i].cost;
            for(int j = max(ne_cost,fuel); j <= cafuel; j++)
            {
                ne_fuel = j - ne_cost;
                if(j > fuel)
                    total = cost+(oil[node]*(j-fuel));
                else
                    total = cost;
                if(total >= arr[ne_node][ne_fuel]) continue;

                arr[ne_node][ne_fuel] = total;
                que.push(data(ne_node,total,ne_fuel));
            }
        }
    }
    return -1;
}

