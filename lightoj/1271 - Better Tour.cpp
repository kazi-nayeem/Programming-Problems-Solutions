#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MX 50005

struct data
{
    int node, dis;
    data() {}
    data(int a, int b)
    {
        node = a;
        dis = b;
    }
    bool operator < (const data & p) const
    {
        if(p.dis != dis) return p.dis < dis;
        return p.node < node;
    }
};

int par[MX], flag[MX];
vector<int> adj[MX];

void bfs(int st, int en);
void print(int st, int en);

int main()
{
    int te, ti, n, u, v, st, en;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &u);
        st = u;
        for(int i = 0; i < MX; i++)
            adj[i].clear();
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &v);
            adj[v].push_back(u);
            adj[u].push_back(v);
            u = v;
        }
        en = u;
        bfs(st,en);
        printf("Case %d:\n", te);
        print(st,en);
        puts("");
    }
    return 0;
}

void print(int st, int en)
{
    if(st == en)
    {
        printf("%d", st);
        return;
    }
    print(st,par[en]);
    printf(" %d", en);
    return;
}

void bfs(int st, int en)
{
    queue<data> qu;
    memset(flag, 0, sizeof flag);
    memset(par, 0, sizeof par);
    flag[st] = 1;
    qu.push(data(st,1));
    int node, dist, n;

    while(!qu.empty())
    {
        node = qu.front().node;
        dist = qu.front().dis;
        qu.pop();

        int sz = adj[node].size();
        sort(adj[node].begin(), adj[node].end());
        //printf("%d %d %d\n", node, dist, sz);
        for(int i = 0; i < sz; i++)
        {
            n = adj[node][i];
            //printf("%d\n", n);
            if(flag[n] != 0) continue;
            flag[n] = dist+1;
            par[n] = node;
            if(n == en) return;
            qu.push(data(n,dist+1));
        }
    }
    return;
}
