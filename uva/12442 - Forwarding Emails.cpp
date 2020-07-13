#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define MX 50005

int adj[MX];
int flag[MX];
int col[MX];

int dfs(int n)
{
    if(col[n] == 1) return 0;
    flag[n] = 0;
    col[n] = 1;
    flag[n] = 1+dfs(adj[n]);
    col[n] = 0;
    return flag[n];
}

int main()
{
    int te, ti, node, u, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &node);
        for(int i = 1; i <= node; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u] = v;
        }
        int mx = 0, no = 0, tm;
        memset(flag,-1, sizeof flag);
        memset(col,0, sizeof col);
        for(int i = 1; i <= node; i++)
        {
            if(flag[i] == -1)
                dfs(i);
            if(flag[i] > mx)
            {
                mx = flag[i];
                no = i;
            }
        }
        printf("Case %d: %d\n",te, no);
    }
    return 0;
}
