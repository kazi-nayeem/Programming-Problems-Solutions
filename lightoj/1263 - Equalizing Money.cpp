#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 1005

vector<int> adj[MX];
int money[MX];
char flag[MX];
int each;

int dfs(int n);

int main()
{
    int n, te, ti, m, u, v, total;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &m);
        memset(flag, 0, sizeof flag);
        total = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", money+i);
            total += money[i];
            adj[i].clear();
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(total % n)
        {
            printf("Case %d: No\n", te);
            continue;
        }
        each = total / n;
        int fl = 1;
        for(int i = 1; i <= n; i++)
        {
            if(flag[i] == 0)
            {
                if(dfs(i) != 0)
                {
                    fl = 0;
                    break;
                }
            }
        }
        if(fl)
            printf("Case %d: Yes\n", te);
        else
            printf("Case %d: No\n", te);
    }
    return 0;
}


int dfs(int n)
{
    //if(flag[n] == 1) return 0;
    flag[n] = 1;
    int total = 0, sz = adj[n].size();
    for(int i = 0; i < sz; i++)
        if(flag[adj[n][i]] == 0)
        total += dfs(adj[n][i]);
    total += money[n]-each;
    return total;
}
