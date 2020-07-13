#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

struct data
{
    int u, w;
    data(int a, int b)
    {
        u = a;
        w = b;
    }
};

vector<data> adj[10000];
int flag[1005][1050];

int bfs(int s, int e)
{
    queue<data>  qu;
    qu.push(data(s,0));
    flag[s][0] = 1;
    while(!qu.empty())
    {
        int u = qu.front().u;
        int w = qu.front().w;
        qu.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].u;
            int tw = adj[u][i].w | w;
            if(flag[v][tw] == 1) continue;
            flag[v][tw] = 1;
            qu.push(data(v,tw));
        }
    }
    for(int i = 0; i < 1050; i++)
    {
        if(flag[e][i] == 1) return i;
    }
    return -1;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, u, v, w, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(data(v,w));
        adj[v].push_back(data(u,w));
    }
    scanf("%d %d", &a, &b);
    printf("%d\n", bfs(a,b));
    return 0;
}
