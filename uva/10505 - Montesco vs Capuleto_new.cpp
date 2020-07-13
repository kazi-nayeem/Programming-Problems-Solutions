#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;

#define MX 20005

vector<int> adj[MX];
int flag[MX];

int bfs(int n);

int main()
{
    int time, test, edge, node, maxi, u, v;
    map<int , int > mp;

    scanf("%d", &time);
    for(test = 1; test <= time; test++)
    {
        mp.clear();
        node = 0;

        scanf(" %d", &edge);
        for(int i = 0; i < edge; i++)
        {
            scanf(" %d %d", &u, &v);

            if(mp.find(u) == mp.end())
                mp[u] = ++node;
            if(mp.find(v) == mp.end())
                mp[v] = ++node;

            u = mp[u];
            v = mp[v];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(flag, 0, sizeof flag);
        maxi = 0;

        for(int i = 1; i <= node; i++)
        {
            if(flag[i] != 0) continue;

            maxi += bfs(i);
        }
        printf("Case %d: %d\n", test, maxi);

        for(int i = 0; i <= node; i++)
            adj[i].clear();
    }

    return 0;
}

int bfs(int n)
{
    queue<int> qu;

    qu.push(n);
    flag[n] = 1;

    int one = 0, two = 0, c, k;
    while(!qu.empty())
    {
        n = qu.front();
        qu.pop();

        c = flag[n];

        if(c == 1)
            one++, c = 2;
        else
            two++, c = 1;

        int sz = adj[n].size();
        for(int i = 0; i < sz; i++)
        {
            k = adj[n][i];
            if(flag[k] == 0)
            {
                qu.push(k);
                flag[k] = c;
            }
        }
    }
    return (one > two)? one:two;
}
