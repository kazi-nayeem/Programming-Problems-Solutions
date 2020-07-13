#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int> mp;
vector<int> adj[55];
int match[350];
int flag[350];

bool dfs(int n)
{
    int sz = adj[n].size(), v;
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(flag[v] == -1)
        {
            flag[v] = 1;
            if(match[v] == -1 || dfs(match[v]))
            {
                match[v] = n;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    mp["XXL"] = 0;
    mp["XL"] = 1;
    mp["L"] = 2;
    mp["M"] = 3;
    mp["S"] = 4;
    mp["XS"] = 5;

    int te, ti;
    int men, col, a, b;
    char str[10];
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &col, &men);
        for(int i = 0; i < men; i++)
        {
            adj[i].clear();
            scanf("%s", str);
            a = mp[str];
            scanf("%s", str);
            b = mp[str];
            for(int j = 0; j < col; j++)
            {
                adj[i].push_back(a*col+j);
                adj[i].push_back(b*col+j);
            }
        }
        bool fla = true;
        memset(match,-1,sizeof match);
        for(int i = 0; i < men; i++)
        {
            memset(flag, -1, sizeof flag);
            if(dfs(i)) continue;
            fla = false;
            break;
        }
        if(fla)
            printf("Case %d: YES\n", te);
        else
            printf("Case %d: NO\n", te);
    }
    return 0;
}
