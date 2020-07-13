#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 30050
#define pii pair<int,int>
#define mkp make_pair

vector<pii > adj[MX];

int dis[MX];
char flag[MX];
int last, lcost;

void dfs1(int node, int cost);
void dfs2(int node, int cost);

int main()
{
    int te, ti, n, u, v, w;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(mkp(v,w));
            adj[v].push_back(mkp(u,w));
        }
        memset(flag, 0, sizeof flag);
        memset(dis, -1, sizeof dis);
        lcost = -1;
        dfs1(0,0);
        memset(flag, 0, sizeof flag);
        lcost = -1;
        //printf("1 %d\n", last);
        dfs2(last,0);
        memset(flag, 0, sizeof flag);
        //printf("2 %d\n", last);
        dfs2(last,0);
        printf("Case %d:\n", te);
        for(int i = 0; i < n; i++)
            printf("%d\n", dis[i]);
    }
    return 0;
}

void dfs1(int node, int cost)
{
    flag[node] = 1;
    int sz = adj[node].size();
    pii tem;
    for(int i = 0; i < sz; i++)
    {
        tem = adj[node][i];
        if(flag[tem.first] != 0) continue;
        dfs1(tem.first,cost+tem.second);
    }
    if(cost > lcost)
    {
        last = node;
        lcost = cost;
    }
    return;
}

void dfs2(int node, int cost)
{
    flag[node] = 1;
    int sz = adj[node].size();
    pii tem;
    for(int i = 0; i < sz; i++)
    {
        tem = adj[node][i];
        if(flag[tem.first] != 0) continue;
        //printf("%d %d\n", tem.first, tem.second);
        dfs2(tem.first,cost+tem.second);
    }
    if(cost > lcost)
    {
        last = node;
        lcost = cost;
    }
    //printf("%d %d\n", node, cost);
    if(dis[node] < cost)
        dis[node] = cost;
    return;
}
