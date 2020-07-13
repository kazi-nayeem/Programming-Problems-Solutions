#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long
#define MX 100050

struct data
{
    int x, y, w;
    double pro;
};

int child[MX];
vector<int> adj[MX];
int n;
data edge[MX];

int dfs(int u, int p)
{
    child[u] = 1;
    for(int i = 0; i < adj[u].size(); i++)
    {
        if(adj[u][i] == p) continue;
        child[u] += dfs(adj[u][i],u);
    }
    return child[u];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].w);
        adj[edge[i].x].push_back(edge[i].y);
        adj[edge[i].y].push_back(edge[i].x);
    }
    dfs(1,1);
    double total = 0.0;
    double div = (double) n*(n-1)/2;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        a = min(child[edge[i].x],child[edge[i].y]);
        b = n-a;
        edge[i].pro = double(double(a)*double(b))/double(div);
        total += double(edge[i].w)*edge[i].pro;
    }
    int q, i, w;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &i, &w);
        total -= (double) double(edge[i].w)*edge[i].pro;
        total += (double) double(w)*edge[i].pro;
        edge[i].w = w;
        printf("%.10lf\n", (double)3.00*total);
    }
    return 0;
}

