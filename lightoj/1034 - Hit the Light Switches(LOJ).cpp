#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define MX 10050

struct data{
    int node, fini;
    bool operator < (const data & p) const
    {
        return p.fini<fini;
    }
};

data flag[MX];
vector<int> adj[MX];
char col[MX];
int n;

void topsort(int node)
{
    if(flag[node].fini != 0) return;
    flag[node].fini = n++;
    int sz = adj[node].size();
    for(int i = 0; i < sz; i++)
        topsort(adj[node][i]);
    flag[node].fini = n++;
    return;
}

void dfs(int node)
{
    if(col[node] != 0) return;
    col[node] = 1;
    int sz = adj[node].size();
    for(int i = 0; i < sz; i++)
        dfs(adj[node][i]);
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int node, te, ti, edge;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &node, &edge);
        for(int i = 0; i <= node; i++)
        {
            adj[i].clear();
            flag[i].node = i;
            flag[i].fini = 0;
        }
        int u, v;
        for(int i = 0; i < edge; i++)
        {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
        }
        n = 1;
        for(int i = 1; i <= node; i++)
        if(flag[i].fini == 0)
            topsort(i);
        sort(flag,flag+node+1);
        //for(int i = 0; i < node; i++)
            //printf("%d %d\n", flag[i].node, flag[i].fini);
        memset(col, 0, sizeof col);
        n = 0;
        for(int i = 0; i < node; i++)
        {
            //printf("%d %d\n", flag[i].node, col[flag[i].node]);
            if(col[flag[i].node] == 0)
            {
                n++;
                dfs(flag[i].node);
            }
        }
        printf("Case %d: %d\n", te, n);
    }
    return 0;
}
