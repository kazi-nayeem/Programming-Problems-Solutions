#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

bool flag[25][25];
vector<int> adj[25];
int maxi;

void backtrack(int node,int sum);

int main()
{
    int node, edge;
    while(scanf("%d %d", &node, &edge) == 2)
    {
        if(node == 0 && edge == 0) return 0;
        for(int i = 0; i < node; i++)
            adj[i].clear();
        for(int i = 0; i < edge; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        maxi = 0;
        for(int i = 0; i < node; i++)
            backtrack(i,0);

        printf("%d\n", maxi);
    }
    return 0;
}

void backtrack(int node,int sum)
{
    if(sum > maxi)
        maxi = sum;
    int sz = adj[node].size(), to;
    for(int i = 0; i < sz; i++)
    {
        to = adj[node][i];
        if(flag[to][node] || flag[node][to]) continue;
        flag[to][node] = true;
        flag[node][to] = true;

        backtrack(to,sum+1);

        flag[to][node] = false;
        flag[node][to] = false;
    }
    return;
}
