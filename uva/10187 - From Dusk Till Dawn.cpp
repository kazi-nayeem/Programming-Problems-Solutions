#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define MX 150
#define inf 1000000

struct data
{
    int u, w, t;
    data() {}
    data(int a, int b, int c)
    {
        u = a, w = b, t = c;
    }
    bool operator < (const data & p) const
    {
        return w>p.w;
    }
};

vector<data> adj[MX];
int dis[MX][14];
map<string,int> mp;

int dijkstra(int start, int fini);

int main()
{
    int te, ti, node, edge, pos;
    char str[100];
    int u, v, st, en;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &edge);
        mp.clear();
        pos = 1;
        while(edge--)
        {
            scanf(" %s", str);
            if(mp.find(str) == mp.end())
            {
                mp[str] = pos;
                adj[pos].clear();
                for(int i = 0; i < 13; i++)
                    dis[pos][i] = inf;
                u = pos;
                pos++;
            }
            else
                u = mp[str];

            scanf(" %s", str);
            if(mp.find(str) == mp.end())
            {
                mp[str] = pos;
                adj[pos].clear();
                for(int i = 0; i < 13; i++)
                    dis[pos][i] = inf;
                v = pos;
                pos++;
            }
            else
                v = mp[str];
            scanf("%d%d", &st, &en);
            st = (st+6)%24;
            en = (en+6)%24;
            if(st <= 12 && en <= 12 && st <= en)
                {
                    adj[u].push_back(data(v,st,en));
                    adj[v].push_back(data(u,st,en));
                }
        }
        node = pos-1;
        scanf(" %s", str);
        u = mp[str];
        scanf(" %s", str);
        v = mp[str];
        int res = dijkstra(u,v);
        printf("%d\n", res);
    }
    return 0;
}

int dijkstra(int start, int fini)
{
    priority_queue<data> qu;
    qu.push(data(start,0,0));
    dis[start][0] = 0;

    int u, v, w, t, ft;
    while(!qu.empty())
    {
        u = qu.top().u;
        w = qu.top().w;
        t = qu.top().t;
        printf("%d %d %d\n", u, w, t);
        qu.pop();
        if(dis[u][t] < w) continue;
        if(u == fini) return w;
        int sz = adj[u].size();
        for(int i = 0; i < sz; i++)
        {
            if(t != adj[u][i].w) continue;
            v = adj[u][i].u;
            ft = adj[u][i].t;
            if(dis[v][ft] > w)
            {
                dis[v][ft] = w;
                qu.push(data(v,w,ft));
            }
        }
        if(t < 12 && dis[u][t+1] > w)
        {
            dis[u][t+1] = w;
            qu.push(data(u,w,t+1));
        }
        else if(dis[u][0] > w+1)
        {
            dis[u][0] = w+1;
            qu.push(data(u,w+1,0));
        }
    }
    return -1;
}
