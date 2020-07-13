#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 205

vector<int> adj[MX];
int flag[MX];
int match[MX];
int arr[MX];

bool dfs(int n)
{
    int v;
    int sz = adj[n].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(flag[v] == 1) continue;
        flag[v] = 1;
        if(match[v] == -1 || dfs(match[v]))
        {
            match[v] = n;
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m, te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
            scanf("%d", &arr[i+n]);
        for(int i = 0; i <= n+m; i++)
            adj[i].clear();
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(arr[j+n]%arr[i] == 0)
                {
                    adj[i].push_back(j+n);
                }
            }
        memset(match, -1, sizeof match);
        int total = 0;
        for(int i = 1; i <= n; i++)
        {
            memset(flag, 0, sizeof flag);
            if(dfs(i)) total++;
        }
        printf("Case %d: %d\n", te, total);
    }
    return 0;
}
