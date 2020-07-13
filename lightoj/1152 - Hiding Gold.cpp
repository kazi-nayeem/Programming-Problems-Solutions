#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<vector>
using namespace std;

#define MX 405

int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};

char str[21][22];
int flag[MX];
int match[MX];
vector<int> adj[MX];

bool dfs(int n)
{
    int v, sz = adj[n].size();
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
    int te, ti, m, n, x, y;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &m, &n);
        gets(str[0]);
        for(int i = 0; i < m; i++)
            gets(str[i]);
        for(int i = 0; i <= m*n; i++)
            adj[i].clear();

        int all = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
        {
            if(str[i][j] == 'o') continue;
            all++;
            for(int k = 0; k < 4; k++)
            {
                x = xx[k]+i;
                y = yy[k]+j;
                if(x < 0 || x >= m || y < 0 || y >= n ) continue;
                if(str[x][y] == 'o') continue;
                adj[i*n+j].push_back(x*n+y);
            }
        }

        memset(match, -1, sizeof match);
        int total = 0;
        for(int i = 0; i < m*n; i++)
        {
            if(str[i/n][i%n] == 'o') continue;
            memset(flag,0,sizeof flag);
            if(dfs(i)) total++;
        }
        printf("Case %d: %d\n", te, all-total/2);
    }
    return 0;
}
