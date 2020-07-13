#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 2005

vector<int> adj[MX];
int colur[MX];
int flag;

void dfs(int node, int co);

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int node, edge;
        scanf("%d %d", &node, &edge);
        for(int i = 0; i <= node; i++)
        {
            adj[i].clear();
            colur[i] = 0;
        }
        for(int i = 0; i < edge; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        flag = 0;
        for(int i = 1; i <= node; i++)
        {
            if(flag) break;
            if(colur[i] == 0)
            dfs(i,2);
        }
        printf("Scenario #%d:\n", te);
        if(flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}

void dfs(int node, int co)
{
    if(colur[node] == co)
    {
        flag = 1;
        return;
    }
    if(colur[node] != 0)
        return;
    co = (co == 1)? 2:1;
    colur[node] = co;
    int sz = adj[node].size();
    for(int i = 0; i < sz; i++)
        dfs(adj[node][i], co);
    return;
}
