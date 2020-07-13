#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 10005

vector<int> adj[MX];
int flag[MX];
int match[MX];
int arr[MX];
int cas;
int res[105][105];
int out[105];
int in[105];
int in_node[MX];
int out_node[MX];

bool dfs(int n)
{
    if(flag[n] == cas) return false;
    flag[n] = cas;

    int u = out_node[n];
    int v;
    int sz = adj[u].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[u][i];
        for(int j = in[v-1]+1; j <= in[v]; j++)
        {
            if(match[j] == -1 || dfs(match[j]))
            {
                match[j] = n;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        adj[i].push_back(i);
        scanf("%d", &out[i]);
        out[i] += out[i-1];
        for(int j = out[i-1]+1; j <= out[i]; j++)
            out_node[j] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
        in[i] += in[i-1];
        for(int j = in[i-1]+1; j <= in[i]; j++)
            in_node[j] = i;
    }
    int u, v;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(in[n] != out[n])
    {
        puts("NO");
        return 0;
    }
    //for(int i = 1; i <= in[n]; i++){
    //  printf("i = %d in_node = %d  out_node = %d\n", i, in_node[i], out_node[i]);
    //}
    memset(match,-1,sizeof match);
    for(int i = 1; i <= in[n]; i++)
    {
        cas++;
        if(dfs(i)) continue;
        //printf("%d\n", i);
        puts("NO");
        return 0;
    }
    for(int i = 1; i <= in[n]; i++)
    {
        res[out_node[match[i]]][in_node[i]]++;
    }
    puts("YES");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d ", res[i][j]);
        puts("");
    }
    return 0;
}
